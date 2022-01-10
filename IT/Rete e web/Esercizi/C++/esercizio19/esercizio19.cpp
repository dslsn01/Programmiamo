/*
file esercizio19.cpp
compilare con: g++ esercizio19.cpp mongoose.c [-lwsock32]
*/

#include "mongoose.h"

static void httpHandler(struct mg_connection* conn, int event, void* ev_data, void* fn_data) {
	if (event == MG_EV_HTTP_MSG) {
		struct mg_http_message* hm = (struct mg_http_message*) ev_data;
		if (!mg_http_match_uri(hm, "/summary")) {
			struct mg_http_serve_opts config = { ".", "#.html" };
			mg_http_serve_dir(conn, hm, &config);
		}
		else {
			char name[50];
			name[0] = 0;
			mg_http_get_var(&hm->body, "nome", name, sizeof(name));

			char surname[50];
			surname[0] = 0;
			mg_http_get_var(&hm->body, "cognome", surname, sizeof(surname));

			if (name[0] == 0 || surname[0] == 0) {
			    mg_http_reply(conn, 400, "Content-Type: text/html; charset=utf-8\n", "Nome e/o cognome mancanti!");
			}

			char address[255];
			address[0] = 0;
			mg_http_get_var(&hm->body, "indirizzo", address, sizeof(address));

			if (address[0] == 0) {
			    mg_http_reply(conn, 400, "Content-Type: text/html; charset=utf-8\n", "Indirizzo mancante!");
			}

			char phone[11];
			phone[0] = 0;
			mg_http_get_var(&hm->body, "telefono", phone, sizeof(phone));

			char email[50];
			email[0] = 0;
			mg_http_get_var(&hm->body, "email", email, sizeof(email));

			if (phone[0] == 0 && email[0] == 0) {
			    mg_http_reply(conn, 400, "Content-Type: text/html; charset=utf-8\n", "Inserire almeno un contatto valido!");
			}

			char ccard[20];
			ccard[0] = 0;
			mg_http_get_var(&hm->body, "credit_card", ccard, sizeof(ccard));

			char verification[4];
			verification[0] = 0;
			mg_http_get_var(&hm->body, "verification", verification, sizeof(verification));

			if (ccard[0] == 0 || strlen(ccard) != 16 || verification[0] == 0 || strlen(verification) != 3) {
			    mg_http_reply(conn, 400, "Content-Type: text/html; charset=utf-8\n", "Numero di carta di credito e/o codice di verifica mancanti o non corretti!");
			}

			mg_http_reply(conn, 200, "Content-Type: text/html; charset=utf-8\n", "<!DOCTYPE html>"
				  "<html>"
				   "<body style=\"text-align: center; \">"
				    "<p>Nome: %s</p>"
				    "<p>Cognome: %s</p>"
				    "<p>Indirizzo: %s</p>"
				    "<p>Telefono: %s</p>"
				    "<p>Email: %s</p>"
				    "<p>Carta di credito: %s</p>"
				   "</body>"
				  "</html>",
				  name, surname, address, phone, email, ccard);
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

