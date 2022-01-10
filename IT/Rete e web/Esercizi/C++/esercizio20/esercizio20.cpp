/*
file esercizio20.cpp
compilare con: g++ esercizio20.cpp mongoose.c [-lwsock32]
*/

#include "mongoose.h"

static void httpHandler(struct mg_connection* conn, int event, void* ev_data, void* fn_data) {
	if (event == MG_EV_HTTP_MSG) {
		struct mg_http_message *hm = (struct mg_http_message*) ev_data;
		struct mg_str *cookieHeader = mg_http_get_header(hm, "cookie");
		struct mg_str bgcol = {};

		if (cookieHeader != NULL) {
			bgcol = mg_http_get_header_var(*cookieHeader, mg_str_n("bgcolor", 7));
		}

		if (bgcol.len == 0) {
			if (mg_http_match_uri(hm, "/theme")) {
				// invia il cookie
				char buf[10];
				mg_http_get_var(&hm->body, "bgcol", buf, sizeof(buf));
				char head[150];
				snprintf(head,
						 sizeof(head),
						 "Location: /\r\n"
						 "Set-Cookie: bgcolor=%s;path=/;Max-Age=3600\n",
						 buf);

				mg_http_reply(conn, 302, head, "");
			}
			else {
				struct mg_http_serve_opts config = { ".", "#.html" };
				mg_http_serve_dir(conn, hm, &config);
			}
		}
		else {
			char cookie[bgcol.len+1];
			snprintf(cookie, sizeof(cookie), bgcol.ptr);
			mg_http_reply(conn, 200,
						  "Content-Type: text/html; charset=utf-8\n",
						  "<!DOCTYPE html>"
						  "<html>"
						   "<body style=\"text-align: center; background-color: %s;\">"
						     "<div style=\"font-weight: bold;\">Benvenuto!</div>"
						   "</body>"
						  "</html>",
						  cookie);
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

