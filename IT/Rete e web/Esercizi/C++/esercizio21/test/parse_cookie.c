/*
file parse_cookie.c
*/

#include "mongoose.h"

static void httpHandler(struct mg_connection* conn, int event, void* ev_data, void* fn_data) {
    if (event == MG_EV_HTTP_MSG) {
        struct mg_http_message *hm = (struct mg_http_message*) ev_data;
        struct mg_str *cookieHeader = mg_http_get_header(hm, "cookie");

        char *cookie = NULL;
        char *lang = NULL;

        if (cookieHeader != NULL) {
            size_t sz = cookieHeader->len;
            char buf[sz+1];
            strncpy(buf, cookieHeader->ptr, sizeof(buf));
            buf[sz] = 0;
            printf("cookie: %s\n", buf);
            cookie = strtok(buf, "; ");
            while (cookie != NULL) {
                 if (strncmp(cookie, "lang", /*sizeof("lang")*/4) == 0) {
                     strtok(cookie, "=");
                 }
                 // printf("lang = %s\n", cookie);
                 lang = cookie;
                 cookie = strtok(NULL, "; ");
            }

            if (lang != NULL) printf("Lingua corrente: %s\n", lang);

            mg_http_reply(conn, 200, "Content-Type: text/html\n", "ok");
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

