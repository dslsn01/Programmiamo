/*
file webserver1.cpp
compilare con: g++ webserver1.cpp mongoose.c (-lwsock32 su Windows)
su macOS: gcc webserver1.cpp mongoose.c
*/

extern "C" {
#include "mongoose.h"
}

static void httpHandler(struct mg_connection* conn, int event, void* ev_data, void* fn_ev_data) {
	if (event == MG_EV_HTTP_MSG) {
		struct mg_http_serve_opts config = { ".", "#.html" };
		mg_http_serve_dir(conn, (struct mg_http_message*) ev_data, &config);
	}
}

int main()
{
	struct mg_mgr eventManager;
	struct mg_connection *conn;

	mg_mgr_init(&eventManager);

	// registra un gestore http che serve le pagine html statiche

	mg_http_listen(&eventManager, "http://localhost:8080", httpHandler, &eventManager);

	// avvia il server web

	while (true) {
		mg_mgr_poll(&eventManager, 1000);
	}

	mg_mgr_free(&eventManager);
}

