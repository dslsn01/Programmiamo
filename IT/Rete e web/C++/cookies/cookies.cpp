/*
file cookies.cpp
compilare con: g++ cookies.cpp mongoose.c (-lwsock32 su Windows)
su macOS: gcc cookies.cpp mongoose.c
*/

#include <ctime>
extern "C" {
#include "mongoose.h"
}

static void httpHandler(struct mg_connection* conn, int event, void* ev_data, void* fn_ev_data) {
	if (event == MG_EV_HTTP_MSG) {
		struct mg_http_message *hm = (struct mg_http_message*) ev_data;
		struct mg_str *cookieHeader = mg_http_get_header(hm, "cookie");
		struct mg_str login = {};

		if (cookieHeader != NULL) {
			login = mg_http_get_header_var(*cookieHeader, mg_str_n("login", 5));
		}

		if (login.len == 0) {
			// se il cookie manca, spedisce un nuovo cookie con la data di connessione
			time_t now = time(NULL);
			struct tm *timeinfo = localtime(&now);
			char buf[25];
			strftime(buf, sizeof(buf), "%d/%m/%Y %H:%M:%S", timeinfo);

			// imposta un cookie valido per un'ora
			char head[100];
			snprintf(head,
					 sizeof(head),
					 "Set-Cookie: login=%s;path=/;Max-Age=3600\r\nContent-Type: text/html; charset=utf-8\n",
					 buf);

			mg_http_reply(conn, 200, head, "Ti sei connesso il %s", buf);
		}
		else {
			// se si trova il cookie, visualizza l'ultima connessione memorizzata
			char cookie[20];
			snprintf(cookie, sizeof(cookie), "%s", login.ptr);
			mg_http_reply(conn, 200, "Content-Type: text/html; charset=utf-8\n", "Ultima connessione: %s", cookie);
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

