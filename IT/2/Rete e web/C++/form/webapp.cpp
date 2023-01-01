/*
file webapp.cpp
compilare con: g++ webapp.cpp mongoose.c (-lwsock32 su Windows)
su macOS: gcc webapp.cpp mongoose.c
*/

#include <cstring>
extern "C" {
#include "mongoose.h"
}

static void httpHandler(struct mg_connection* conn, int event, void* ev_data, void* fn_ev_data) {
	if (event == MG_EV_HTTP_MSG) {
		struct mg_http_message *hm = (struct mg_http_message*) ev_data;
		if (mg_http_match_uri(hm, "/home")) {
			char user[50];
			char pwd[50];
			mg_http_get_var(&hm->body, "username", user, sizeof(user));
			mg_http_get_var(&hm->body, "password", pwd, sizeof(pwd));

			if (user[0] != 0 && pwd[0] != 0 && strcmp(user, pwd) == 0) {
				mg_http_reply(conn,
							  200,
							  "Content-Type: text/html; charset=utf-8\r\n", 
							  "<!DOCTYPE html>"
							  "<html>"
							   "<body>"
							    "<p style=\"font-weight: bold;\">Benvenuto, %s!</p>"
							   "</body>"
							  "</html>",
							  user);
			}
			else {
				mg_http_reply(conn, 401, "Content-Type: text/html; charset=utf-8\r\n", "Username / pwd non corretti!");
			}
		}
		else {
			struct mg_http_serve_opts config = { ".", "#.html" };
			mg_http_serve_dir(conn, (struct mg_http_message*) ev_data, &config);
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

