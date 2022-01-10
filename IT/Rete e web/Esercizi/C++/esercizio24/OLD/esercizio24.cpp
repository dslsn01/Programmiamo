/*
file esercizio24.cpp
compilare con: g++ esercizio24.cpp mongoose.c [-lwsock32]
*/

#include <ctime>
// #include <string>
#include "mongoose.h"

// using std::string;

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
                     char *tokens[2] = {};
                     int i = 0;
                     char* s = strtok(cookie, "=");
                     while (s != NULL) {
                         // printf("s=%s\n", s);
                         // snprintf(user, sizeof(user), s);
                         tokens[i++] = s;
                         // strncpy(tokens[i++], sizeof(tokens));
                         s = strtok(NULL, "=");
                     }
                     if (tokens[1] != NULL) {
                         // printf("i=%d, %s\n", i, tokens[1]);
                         snprintf(user, sizeof(user), tokens[1]);
                     }
                     /*else {
                         printf("null!\n");
                     }
                     */
                 }
                 cookie = strtok(NULL, "; ");
            }
        }

        printf("user: %s\n", user);

        if (user[0] == 0) {
            printf("user[0] == NUL\n");
            if (mg_http_match_uri(hm, "/welcome")) {
                printf("Di nuovo welcome!\n");
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
            /*else if (mg_http_match_uri(hm, "/logout")) {
                // struct mg_http_serve_opts config = { ".", "index.html" };
                // mg_http_serve_dir(conn, hm, &config);

                printf("redirect\n");
                mg_http_reply(conn, 302, "Location: /\n", "");
            }
*/
            else {
                // restituisce la form
                struct mg_http_serve_opts config = { ".", "#.html" };
                mg_http_serve_dir(conn, hm, &config);
            }
        }
        else {
            printf("user[0] diverso da NUL\n");
            if (!mg_http_match_uri(hm, "/logout")) {
                mg_http_reply(conn, 200,
                             "Content-Type: text/html; charset=utf-8\n",
                             "<!DOCTYPE html>"
                             "<html>"
                               "<body style=\"text-align: center\">"
                                 "<p style=\"font-weight: bold;\">Benvenuto, %s!</p>"
                                 "<a href=\"logout\">Esci</a>"
                               "</body>"
                             "</html>",
                             user);
            } else {
                printf("logout!\n");
                time_t now = time(NULL);
                struct tm *timeinfo = localtime(&now);

                char buf[25];
                strftime(buf, sizeof(buf), "%d/%m/%Y %H:%M:%S", timeinfo);

                mg_http_reply(conn, 200,
                         "Set-Cookie: username=\r\nContent-Type: text/html; charset=utf-8\n",
                         "<!DOCTYPE html>"
                         "<html>"
                           "<body style=\"text-align: center\">"
                             "<p>Logout effettuato il %s.</p>"
                           "</body>"
                         "</html>",
                         buf);
            }
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

