/*
file webserver2.cpp
compilare con: g++ webserver2.cpp mongoose.c (-lwsock32 su Windows)
su macOS: gcc webserver2.cpp mongoose.c
*/

extern "C" {
#include "mongoose.h"
}

static void httpHandler(struct mg_connection* conn, int event, void* data, void* fn_data) {
	if (event == MG_EV_HTTP_MSG) {
		// invia la risposta HTTP con codice di stato e Content-Type
		mg_http_reply(conn,
					  200,
					  "Content-Type: text/html; charset=utf-8\n",
					  "<!DOCTYPE html>"
					  "<html>"
					   "<head>"
					    "<title>La mia pagina web</title>"
					   "</head>"
					   "<body>"
					    "<p>Ciao, mondo!</p>"
					   "</body>"
					  "</html>");
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

