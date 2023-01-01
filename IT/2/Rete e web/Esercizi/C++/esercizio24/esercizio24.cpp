/*
file esercizio24.cpp
compilare con: g++ -std=c++11 esercizio24.cpp mongoose.c [-lwsock32]
*/

#include <ctime>
#include "mongoose.h"

static void httpHandler(struct mg_connection* conn, int event, void* ev_data, void* fn_data) {
	if (event == MG_EV_HTTP_MSG) {
		struct mg_http_message *hm = (struct mg_http_message*) ev_data;
		struct mg_str *cookieHeader = mg_http_get_header(hm, "cookie");
		struct mg_str user = {};

		if (cookieHeader != NULL) {
			user = mg_http_get_header_var(*cookieHeader, mg_str_n("username", 8));
		}

		if (user.ptr == 0) {
			if (mg_http_match_uri(hm, "/welcome")) {
				// invia il cookie
				char buf[50];
				mg_http_get_var(&hm->body, "name", buf, sizeof(buf));
				const char* s = buf[0] != 0 ? buf : "ignoto";
				char head[150];
				snprintf(head,
						 sizeof(head),
						 "Location: /\r\n"
						 "Set-Cookie: username=%s;path=/;Max-Age=3600\n",
						 s); // cookie valido per un'ora

				mg_http_reply(conn, 302, head, "");
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
				time_t now = time(NULL);
				struct tm *timeinfo = localtime(&now);
				char buf[25];
				strftime(buf, sizeof(buf), "%d/%m/%Y %H:%M:%S", timeinfo);

				mg_http_reply(conn,
							  200,
							  "Set-Cookie: username=\r\nContent-Type: text/html; charset=utf-8\n",
							  "<!DOCTYPE html>"
							  "<html>"
							   "<body style=\"text-align: center\">"
							    "<div>Logout effettuato il %s.</div>"
							   "</body>"
							  "</html>",
							  buf);
			} else {
				char cookie[user.len+1];
				snprintf(cookie, sizeof(cookie), user.ptr);
				mg_http_reply(conn, 200,
							  "Content-Type: text/html; charset=utf-8\n",
							  "<!DOCTYPE html>"
							  "<html>"
							   "<body style=\"text-align: center\">"
							    "<div style=\"font-weight: bold;\">Benvenuto, %s!</div>"
							    "<a href=\"logout\">Esci</a>"
							   "</body>"
							  "</html>",
							  cookie);
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

