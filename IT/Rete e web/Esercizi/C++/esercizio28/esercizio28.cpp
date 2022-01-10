/*
file esercizio28.cpp
compilare con: g++ -std=c++11 esercizio28.cpp mongoose.c [-lwsock32]
*/

#define __STDC_FORMAT_MACROS 1

#include <inttypes.h>
#include <string>
#include <list>
#include "mongoose.h"

using std::string;
using std::stoull;
using std::to_string;
using std::list;

typedef struct {
	uint64_t id;
	string username;
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
			if (mg_http_match_uri(hm, "/welcome")) {
				userSession = new Session();
				char buf[50];
				buf[0] = 0;
				mg_http_get_var(&hm->body, "name", buf, sizeof(buf));
				const char* s = buf[0] != 0 ? buf : "ignoto";

				char buf2[50];
				buf2[0] = 0;
				mg_http_get_var(&hm->body, "password", buf2, sizeof(buf2));
 				if (strncmp(buf, buf2, sizeof(buf)) == 0) {
					const char* s = buf[0] != 0 ? buf : "ignoto";

					mg_sha1_ctx ctx;
					mg_sha1_init(&ctx);
					mg_sha1_update(&ctx, (const unsigned char*) hm->message.ptr, hm->message.len);
					mg_sha1_update(&ctx, (const unsigned char*) userSession, sizeof(*userSession));

					unsigned char digest[30];
					mg_sha1_final(digest, &ctx);

					// converte l'id di sessione in numero
					uint64_t _digest = *reinterpret_cast<uint64_t*>(digest);
					userSession->id = _digest;
					userSession->username = s;

					server.sessions.push_back(userSession);

					// invia il cookie di sessione
					char head[150];
					snprintf(head,
							 sizeof(head),
							 "Location: /\r\n"
							 "Set-Cookie: session_id=%" PRIu64 ";path=/\n",
							 _digest);

					mg_http_reply(conn, 302, head, "");
				}
				else {
					mg_http_reply(conn, 401, "Content-Type: text/html; charset=utf-8\n", "Username / password non corretti");
				}
			}
			else if (mg_http_match_uri(hm, "/logout")) {
				mg_http_reply(conn, 302, "Location: /\n", "");
			}
			else {
				// restituisce la form
				struct mg_http_serve_opts config = { ".", "#.html" };
				mg_http_serve_dir(conn, hm, &config);
			}
		}
		else {
			if (mg_http_match_uri(hm, "/logout"))
			{
				uint64_t sid = stoull(sessionId.ptr);

				for (auto& session : server.sessions) {
					if (session->id == sid) {
						delete session;
						break;
					}
				}

				char head[150];
				snprintf(head,
						 sizeof(head),
						 "Location: /\r\n"
						 "Set-Cookie: session_id=\n");

				mg_http_reply(conn, 302, head, "");
			} else {
				mg_http_reply(conn, 200,
							  "Content-Type: text/html; charset=utf-8\n",
							  "<!DOCTYPE html>"
							  "<html>"
							   "<body style=\"text-align: center\">"
							    "<div style=\"font-weight: bold;\">Benvenuto, %s!</div>"
							    "<a href=\"logout\">Esci</a>"
							   "</body>"
							  "</html>",
							  userSession->username.c_str());
			}
		}
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

