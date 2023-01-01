/*
file esercizio22.cpp
compilare con: g++ -std=c++11 esercizio22.cpp mongoose.c [-lwsock32]
*/

#define __STDC_FORMAT_MACROS 1

#include <inttypes.h>
#include <string>
#include <list>
#include "mongoose.h"

using std::stoull;
using std::to_string;
using std::list;

typedef struct {
	uint64_t id;
	int counter;
} Session;

class Server {
	public:
		list<Session*> sessions;

	virtual ~Server();
};

Server::~Server() {
	for (Session *session : sessions) {
		delete session;
	}
	sessions.clear();
}

Server server;

static void httpHandler(struct mg_connection* conn, int event, void* ev_data, void* fn_data) {
	if (event == MG_EV_HTTP_MSG) {
		struct mg_http_message *hm = (struct mg_http_message*) ev_data;
		struct mg_str *cookieHeader = mg_http_get_header(hm, "cookie");
		struct mg_str sessionId = {};

		if (cookieHeader != NULL) {
			sessionId = mg_http_get_header_var(*cookieHeader, mg_str_n("session_id", 10));
		}

		Session *userSession = NULL;

		if (sessionId.ptr != 0) {
			char buf[sessionId.len+1];
			snprintf(buf, sizeof(buf), sessionId.ptr);
			uint64_t sid = stoull(buf);

			for (auto& session : server.sessions) {
				if (session->id == sid) {
					userSession = session;
				}
			}
		}

		char head[100];

		if (!userSession) {
			userSession = new Session();

			/* crea un id di sessione con l'algoritmo di crittazione SHA-1 */

			mg_sha1_ctx ctx;
			mg_sha1_init(&ctx);
			mg_sha1_update(&ctx, (const unsigned char*) hm->message.ptr, hm->message.len);
			mg_sha1_update(&ctx, (const unsigned char*) userSession, sizeof(*userSession));

			unsigned char digest[30];
			mg_sha1_final(digest, &ctx);

			uint64_t _digest = *reinterpret_cast<uint64_t*>(digest);
			userSession->id = _digest;

			server.sessions.push_back(userSession);

			snprintf(head,
					 sizeof(head),
					 "Set-Cookie: session_id=%" PRIu64 ";path=/\r\nContent-Type: text/html; charset=utf-8\n",
					 _digest);
		}
		else {
			snprintf(head, sizeof(head), "Content-Type: text/html; charset=utf-8\n");
		}

		userSession->counter++;

		mg_http_reply(conn,
					  200,
					  head,
					  "<!DOCTYPE html>"
					  "<html>"
					   "<body>"
					    "<div>Sei passato a trovarci %d volte!</div>"
					   "</body>"
					  "</html>",
					  userSession->counter);
	}
}

int main()
{
	struct mg_mgr eventManager;
	struct mg_connection *conn;

	mg_mgr_init(&eventManager);

	mg_http_listen(&eventManager, "http://localhost:8080", httpHandler, &eventManager);

	while (true) {
		mg_mgr_poll(&eventManager, 1000);
	}

	mg_mgr_free(&eventManager);
}

