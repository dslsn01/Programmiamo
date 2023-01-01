/*
file esercizio22.cpp
compilare con: g++ -std=c++11 esercizio22.cpp mongoose.c [-lwsock32]
*/

// #define __STDC_FORMAT_MACROS

#include <inttypes.h>
#include <string>
#include <list>
#include "mongoose.h"

using std::string;
using std::stoull;
using std::to_string;
using std::list;

#include <iostream>

using std::cout;
using std::endl;
using std::boolalpha;

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
        Session *userSession = NULL;

        struct mg_http_message *hm = (struct mg_http_message*) ev_data;
        struct mg_str *cookieHeader = mg_http_get_header(hm, "cookie");

		// Se il cookie non è ancora stato inviato
		// vecchio codice
		/*
		char sessionId[21];
		char *charbuf = sessionId;

		if (cookieHeader && mg_http_parse_header2(cookieHeader, "session_id", &charbuf, sizeof(sessionId))) {
			uint64_t sid = stoull(sessionId);

			for (auto& session : server.sessions) {
				if (session->id == sid) {
					userSession = session;
				}
			}
		}
		*/

        char *cookie = NULL;
        char sessionId[21];
        sessionId[0] = 0;

        if (cookieHeader != NULL) {
            size_t sz = cookieHeader->len;
            char buf[sz+1];
            // strncpy(buf, cookieHeader->ptr, sizeof(buf));
            // buf[sz] = 0;
            snprintf(buf, sizeof(buf), cookieHeader->ptr);
            cookie = strtok(buf, "; ");

            while (cookie != NULL) {
                 if (strncmp(cookie, "session_id", 10) == 0) {
                     const char* s = strtok(cookie, "=");
                     while (s != NULL) {
                         // strncpy(sessionId, s, sizeof(sessionId));
                         snprintf(sessionId, sizeof(sessionId), s);
                         // sessionId[20] = 0;
                         s = strtok(NULL, "=");
                     }
                 }
                 cookie = strtok(NULL, "; ");
            }
        }

        printf("id di sessione (recuperato dal cookie) %s\n", sessionId);

        if (sessionId[0] != 0) {
            uint64_t sid = stoull(sessionId);
            printf("id di sessione (convertito in uint64_t): %PRIu64\n", sid);

            for (auto& session : server.sessions) {
                printf("Nel server: id sessione corrente: %PRIu64, id letto dal cookie: %" PRIu64 "\n", session->id, sid);
                cout << boolalpha << (session->id == sid) << endl;

                if (session->id == sid) {
                    printf("Sessione trovata!\n");
                    userSession = session;
                }
            }
        }

        char head[100];
        // head[0] = 0;

        if (!userSession) {
            printf("Utente non in sessione!\n");
            userSession = new Session();

            /* crea un id di sessione con l'algoritmo di crittazione SHA-1 */

            mg_sha1_ctx ctx;
            mg_sha1_init(&ctx);
            mg_sha1_update(&ctx, (const unsigned char*) hm->message.ptr, hm->message.len);
            mg_sha1_update(&ctx, (const unsigned char*) userSession, sizeof(*userSession));

            unsigned char digest[30];
            mg_sha1_final(digest, &ctx);
            printf("digest: %s\n", digest);

            // converte l'id di sessione in numero
            // uint64_t _digest = *reinterpret_cast<uint64_t*>(digest);
            uint64_t _digest = *(uint64_t*) digest;
            // _digest = 111100001;
            userSession->id = _digest;

            printf("id di sessione (appena generato): %PRIu64\n", _digest);

            server.sessions.push_back(userSession);
            snprintf(head, sizeof(head), "Set-Cookie: session_id=%" PRIu64 ";path=/\r\nContent-Type: text/html; charset=utf-8\n", _digest);
            // string tmp = "Set-Cookie: session_id=" + to_string(_digest) + ";path=/\r\nContent-Type: text/html; charset=utf-8\n";
            // strncpy(head, tmp.c_str(), sizeof(head));
        }
        else {
            snprintf(head, sizeof(head), "Content-Type: text/html; charset=utf-8\n");
        }

        // if (head[0] == 0) {
        //     strncpy(head, "Content-Type: text/html; charset=utf-8\n", sizeof(head));
        // }

        userSession->counter++;

        mg_http_reply(conn, 200,
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

