/*
file esercizio21.cpp
compilare con: g++ esercizio21.cpp mongoose.c [-lwsock32]
*/

#include "mongoose.h"

static void httpHandler(struct mg_connection* conn, int event, void* ev_data, void* fn_data) {
    if (event == MG_EV_HTTP_MSG) {
        struct mg_http_message *hm = (struct mg_http_message*) ev_data;
        struct mg_str *cookieHeader = mg_http_get_header(hm, "cookie");

        char *cookie = NULL;
        char lang[3];
        lang[0] = 0;

        if (cookieHeader != NULL) {
            size_t sz = cookieHeader->len;
            char buf[sz+1];
            snprintf(buf, sizeof(buf), cookieHeader->ptr);
            cookie = strtok(buf, "; ");

            while (cookie != NULL) {
                 if (strncmp(cookie, "lang", 4) == 0) {
                     const char* s = strtok(cookie, "=");
                     while (s != NULL) {
                         snprintf(lang, sizeof(lang), s);
                         s = strtok(NULL, "=");
                     }
                 }
                 cookie = strtok(NULL, "; ");
            }
        }

        if (lang[0] == 0) {
            if (!mg_http_match_uri(hm, "/lang")) {
                struct mg_http_serve_opts config = { ".", "#.html" };
                mg_http_serve_dir(conn, hm, &config);
            }
            else {
                // invia il cookie
                char buf[10];
                mg_http_get_var(&hm->body, "lang", buf, sizeof(buf));
                char head[150];
                snprintf(head,
                         sizeof(head),
                         "Location: /\r\n"
                         "Set-Cookie: lang=%s;path=/;Max-Age=3600\n",
                         buf);

                mg_http_reply(conn, 302, head, "");
            }
        }
        else {
            const char* msg = strcmp(lang, "it") == 0 ? "Benvenuto!" : "Welcome!";
            mg_http_reply(conn, 200,
                         "Content-Type: text/html; charset=utf-8\n",
                         "<!DOCTYPE html>"
                         "<html>"
                           "<body style=\"text-align: center;\">"
                             "<div style=\"font-weight: bold;\">%s</div>"
                           "</body>"
                         "</html>",
                         msg);
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

