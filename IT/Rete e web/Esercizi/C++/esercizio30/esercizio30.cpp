/*
file esercizio30.cpp
compilare con: g++ -std=c++11 esercizio30.cpp mongoose.c [-lwsock32]
*/

#include <string>
#include "mongoose.h"

using std::string;
using std::stoi;
using std::stod;
using std::to_string;

static void httpHandler(struct mg_connection* conn, int event, void* ev_data, void* fn_data) {
	if (event == MG_EV_HTTP_MSG) {
		struct mg_http_message *hm = (struct mg_http_message*) ev_data;

		if (mg_http_match_uri(hm, "/beratio")) {
			char loan[20];
			mg_http_get_var(&hm->body, "loan", loan, sizeof(loan));

			char debts[20];
			mg_http_get_var(&hm->body, "debts", debts, sizeof(debts));

			char nMonths[20];
			mg_http_get_var(&hm->body, "nMonths", nMonths, sizeof(nMonths));

			char income[20];
			mg_http_get_var(&hm->body, "income", income, sizeof(income));

			double _loan = stod(loan);
			double taeg = (_loan / 100) * 6.5;
			double _debts = stod(debts);
			int _nMonths = stoi(nMonths);
			double _income = stod(income);

			// calcola la rata mensile (incluso il TAEG): 
			double payment = ((_loan + taeg) / _nMonths);

			char buf[500];
			snprintf(buf,
					 sizeof(buf), 
					 "<!DOCTYPE html>"
					 "<html>"
					   "<body style=\"text-align: center\">"
					     "<div style=\"font-style: italic;\">Riassunto</div><br/>"
					     "<div>Prestito richiesto: %s euro</div>"
					     "<div>Reddito mensile: %s euro</div>"
					     "<div>Totale debiti pregressi: %s euro mensili</div>"
					     "<div>Numero rate desiderato: %s </div><br/>"
					     "<div style=\"font-weight: bold\">Importo rata mensile: %.2f </div>"
					     "<div>(Alla rata si applica un tasso di interesse annuo globale del 6.5%%%% annuo)</div><br/>",
					 loan,
					 income,
					 debts,
					 nMonths,
					 payment);

			double beratio = ((payment + _debts) / _income) * 100;

			if (beratio <= 36) {
				snprintf(buf + strlen(buf),
						 120,
						 "<div style=\"color:green;\">Rapporto debiti / reddito uguale a %.2f%. Possiamo concedere il prestito.</div>",
						 beratio);
			}
			else {
				snprintf(buf + strlen(buf),
						 120,
						 "<div style=\"color:red;\">Rapporto debiti / reddito eccessivo (%.2f%). Impossibile concedere il prestito.</div>",
						 beratio);
			}

			snprintf(buf + strlen(buf), 15, "</body></html>");

			mg_http_reply(conn, 200, "Content-Type: text/html; charset=utf-8\n", buf);
		}
		else {
			struct mg_http_serve_opts config = { ".", "#.html" };
			mg_http_serve_dir(conn, hm, &config);
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

