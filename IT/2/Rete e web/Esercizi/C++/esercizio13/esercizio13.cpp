/* 
file esercizio13.cpp
compilare con: g++ esercizio13.cpp mongoose.c [-lwsock32]
*/

#include "mongoose.h"

static void httpHandler(struct mg_connection* conn, int event, void* ev_data, void* fn_data) {
	if (event == MG_EV_HTTP_MSG) {
		time_t now = time(NULL);
		struct tm *timeinfo = localtime(&now);
		char fmt[80];
		strftime(fmt, sizeof(fmt), "%d/%m/%Y ore %H:%M:%S", timeinfo);

		mg_http_reply(conn, 200, "Content-Type: text/html\n", "Ti sei connesso il %s", fmt);
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

	return 0;
}

