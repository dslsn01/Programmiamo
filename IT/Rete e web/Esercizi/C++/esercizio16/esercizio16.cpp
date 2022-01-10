/*
file esercizio16.cpp
compilare con: g++ esercizio16.cpp mongoose.c [-lwsock32]
*/

#include "mongoose.h"

static void httpHandler(struct mg_connection* conn, int event, void* ev_data, void* fn_data) {
	if (event == MG_EV_HTTP_MSG) {
		struct mg_http_message* hm = (struct mg_http_message*) ev_data;
		if (!mg_http_match_uri(hm, "/welcome")) {
			struct mg_http_serve_opts config = { ".", "#.html" };
			mg_http_serve_dir(conn, hm, &config);
		}
		else {
			char buf[50];
			buf[0] = 0;
			mg_http_get_var(&hm->query, "name", buf, sizeof(buf));
			const char *name = buf[0] != 0 ? buf : "ignoto";
			mg_http_reply(conn,
						  200,
						  "Content-Type: text/html; charset=utf-8\n", 
						  "<!DOCTYPE html>"
						  "<html>"
						   "<body style=\"text-align: center\">"
						    "<div style=\"font-weight: bold;\">Benvenuto, %s!</div>"
						   "</body>"
						  "</html>",
						  name);
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

