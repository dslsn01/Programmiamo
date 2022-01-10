/*
file esercizio21.cpp
compilare con: g++ esercizio21.cpp mongoose.c [-lwsock32]
*/

#include "mongoose.h"

/*
#include <iostream>

using std::string;
using std::cout;
using std::endl;
*/

static void httpHandler(struct mg_connection* conn, int event, void* ev_data, void* fn_data) {
    if (event == MG_EV_HTTP_MSG) {
        struct mg_http_message *hm = (struct mg_http_message*) ev_data;
        struct mg_str *cookieHeader = mg_http_get_header(hm, "cookie");
        size_t sz = cookieHeader->len;
        // printf("Cookie size: %d\n", sz);
        // printf("%s\n", hm->headers[0].value);
        // printf("%s, %d\n", cookieHeader->ptr, cookieHeader->len);

        char *lang = NULL;

        if (cookieHeader != NULL) {
            char buf[sz+1];
            strncpy(buf, cookieHeader->ptr, sizeof(buf));
            buf[sz] = 0;
            // printf("buffer: %s\n", buf);
            // cout << buf << endl;
            // cout << string(cookieHeader->ptr).substr(0, sz) << endl;
            char *lang = strtok(buf, "; ");
            // char *lang = NULL;
            while (lang != NULL) {
                 printf("cookie %s\n", lang);
                 // int r = strncmp(cookie, "lang", /*sizeof("lang")*/4);
                 // printf("risultato di strcmp: %d\n", r);
                 if (strncmp(lang, "lang", /*sizeof("lang")*/4) == 0) {
                     // printf("%s\n", lang);
                     // printf("Trovato il cookie \"lang\"!\n");
                     /*char *token = */strtok(lang, "=");
                     // printf("token: %s\n", token);
                    /* while (token != NULL) {
                        lang = token;
                        token = strtok(NULL, "=");
                    }*/
                 }
                 lang = strtok(NULL, "; ");
            }
        }

        // printf("fuori\n");
        // printf("%s\n", lang);

        if (lang == NULL) {
            if (!mg_http_match_uri(hm, "/lang")) {
                struct mg_http_serve_opts config = { ".", "#.html" };
                mg_http_serve_dir(conn, hm, &config);
            }
            else {
                // invia il cookie
                char bg[10];
                mg_http_get_var(&hm->body, "lang", bg, sizeof(lang));
                char head[150];
                snprintf(head,
                         sizeof(head),
                         "Location: /\r\n"
                         "Set-Cookie: lang=%s\n;path=/;Max-Age=3600"
                         "Content-Type: text/html\r\n"
                         "Cache-Control: no-cache\r\n\r\n", 
                bg);
                mg_http_reply(conn, 302, head, "");
            }
        }
        else {
            const char* msg = (strcmp(lang, "it") == 0) ? "Benvenuto!" : "Welcome!";
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

