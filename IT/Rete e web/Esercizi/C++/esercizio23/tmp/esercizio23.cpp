/*
file esercizio23.cpp
compilare con: g++ esercizio23.cpp mongoose.c [-lwsock32]
*/

#include "mongoose.h"

static void httpHandler(struct mg_connection* conn, int event, void* ev_data, void* fn_data) {
    if (event == MG_EV_HTTP_MSG) {
        struct mg_http_message *hm = (struct mg_http_message*) ev_data;
        struct mg_str *cookieHeader = mg_http_get_header(hm, "cookie");

        char *cookie = NULL;
        char user[50];
        user[0] = 0;

        if (cookieHeader != NULL) {
            size_t sz = cookieHeader->len;
            char buf[sz+1];
            snprintf(buf, sizeof(buf), cookieHeader->ptr);
            cookie = strtok(buf, "; ");

            while (cookie != NULL) {
                 if (strncmp(cookie, "username", 8) == 0) {
                     const char* s = strtok(cookie, "=");
                     while (s != NULL) {
                         snprintf(user, sizeof(user), s);
                         s = strtok(NULL, "=");
                     }
                 }
                 cookie = strtok(NULL, "; ");
            }
        }

        if (user[0] == 0) {
            if (!mg_http_match_uri(hm, "/welcome")) {
                // restituisce la form
                struct mg_http_serve_opts config = { ".", "#.html" };
                mg_http_serve_dir(conn, hm, &config);
            }
            else {
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
        }
        else {
            mg_http_reply(conn, 200,
                         "Content-Type: text/html; charset=utf-8\n",
                         "<!DOCTYPE html>"
                         "<html>"
                           "<body style=\"text-align: center\">"
                             "<p style=\"font-weight: bold;\">Benvenuto, %s!</p>"
                           "</body>"
                         "</html>",
                         user);
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

