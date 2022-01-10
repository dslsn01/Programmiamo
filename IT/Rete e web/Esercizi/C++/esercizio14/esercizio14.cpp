/*
file esercizio14.cpp
compilare con: g++ esercizio14.cpp mongoose.c [-lwsock32]
*/

#include "mongoose.h"

static void httpHandler(struct mg_connection* conn, int event, void* ev_data, void* fn_data) {
	if (event == MG_EV_HTTP_MSG) {
		struct mg_http_message* hm = (struct mg_http_message*) ev_data;
		const char* uri = "/redirect.html";
		if (!mg_http_match_uri(hm, uri)) {
			char head[150];
			snprintf(head, sizeof(head), 
						  "Location: %s\r\n"
						  "Content-Type: text/html\r\n"
						  "Content-Length: %d\r\n"
						  "Cache-Control: no-cache\r\n\r\n",
						  uri,
						  strlen(uri)
			);
			mg_http_reply(conn, 301, head, "");
		}
		else {
			struct mg_http_serve_opts config = {".", "#.html"};
			mg_http_serve_dir(conn, hm, &config);
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

