/*
file sessions.cpp
compilare con: g++ -std=c++11 sessions.cpp mongoose.c (-lwsock32 su Windows)
su macOS: 
gcc -c mongoose.c
g++ -std=c++11 sessions.cpp mongoose.o
*/

#define __STDC_FORMAT_MACROS 1

#include <inttypes.h>
#include <ctime>
#include <list>
#include <string>
extern "C" {
#include "mongoose.h"
}

using std::string;
using std::stoull;
using std::to_string;
using std::list;

typedef struct {
	uint64_t id;
	struct tm *timeinfo;
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

// crea un server con una lista di sessioni
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
			snprintf(buf, sizeof(buf), "%s", sessionId.ptr);
			uint64_t sid = stoull(buf);

			for (auto& session : server.sessions) {
				if (session->id == sid) {
					userSession = session;
				}
			}
		}

		/* se la sessione non si trova, crea una nuova sessione dove memorizza l'ora corrente */
		if (!userSession) {
			userSession = new Session();

			time_t now = time(NULL);
			struct tm *timeinfo = localtime(&now);
			userSession->timeinfo = timeinfo;

			// prepara il cookie di sessione
			mg_sha1_ctx ctx;
			mg_sha1_init(&ctx);
			mg_sha1_update(&ctx, (const unsigned char*) hm->message.ptr, hm->message.len);
			mg_sha1_update(&ctx, (const unsigned char*) userSession, sizeof(*userSession));

			unsigned char digest[30];
			mg_sha1_final(digest, &ctx);

			// converte l'id di sessione in numero
			uint64_t _digest = *reinterpret_cast<uint64_t*>(digest);
			userSession->id = _digest;

			// salva la nuova sessione sul server web
			server.sessions.push_back(userSession);

			// imposta un cookie di sessione valido a tempo indeterminato
			char head[100];
			snprintf(head,
					 sizeof(head),
					 "Set-Cookie: session_id=%" PRIu64 ";path=/\r\nContent-Type: text/html; charset=utf-8\n",
					 _digest);

			char buf[25];
			strftime(buf, sizeof(buf), "%d/%m/%Y %H:%M:%S", timeinfo);

			mg_http_reply(conn, 200, head, "Ti sei connesso il %s", buf);
		}
		else {
			/* se presente, visualizza l'ora dell'ultima connessione in sessione */
			struct tm *timeinfo = userSession->timeinfo;
			char login[25];
			strftime(login, sizeof(login), "%d/%m/%Y %H:%M:%S", timeinfo);
			mg_http_reply(conn, 200, "Content-Type: text/html; charset=utf-8\n", "Ultima connessione: %s", login);
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

