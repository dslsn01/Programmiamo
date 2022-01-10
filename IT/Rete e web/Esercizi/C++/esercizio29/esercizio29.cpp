/*
file esercizio29.cpp
compilare con: g++ -std=c++11 esercizio29.cpp mongoose.c [-lwsock32]
*/

#include <string>
#include <unordered_map>
#include "mongoose.h"

using std::string;
using std::to_string;
using std::unordered_map;
using std::make_pair;

unordered_map<string, double> prices;

static void httpHandler(struct mg_connection* conn, int event, void* ev_data, void* fn_data) {
	if (event == MG_EV_HTTP_MSG) {
		struct mg_http_message *hm = (struct mg_http_message*) ev_data;

		if (mg_http_match_uri(hm, "/summary")) {
			char smartphone[20];
			smartphone[0] = 0;
			mg_http_get_var(&hm->body, "smartphone", smartphone, sizeof(smartphone));

			char notebook[20];
			notebook[0] = 0;
			mg_http_get_var(&hm->body, "notebook", notebook, sizeof(notebook));

			char tv[20];
			tv[0] = 0;
			mg_http_get_var(&hm->body, "tv", tv, sizeof(tv));

			double total = 0.0;

			char buf[500];
			snprintf(buf,
					 sizeof(buf), 
					 "<!DOCTYPE html>"
					 "<html>"
					   "<body style=\"text-align: center\">"
					     "<h2>Riassunto acquisti (IVA inclusa):</h2>");

			const char* p = "<div>%s = %.2f euro</div>";

			if (smartphone[0] != 0) {
				double price = prices[smartphone];
				total += price;
				snprintf(buf + strlen(buf), 50, p, smartphone, price);
			}

			if (notebook[0] != 0) {
				double price = prices[notebook];
				total += price;
				snprintf(buf + strlen(buf), 50, p, notebook, price);
			}

			if (tv[0] != 0) {
				double price = prices[tv];
				total += price;
				snprintf(buf + strlen(buf), 50, p, notebook, price);
			}

			if (total != 0.0) {
				snprintf(buf + strlen(buf), 100, "<br/><div style=\"font-weight: bold\">Totale spesa: %.2f euro.</div>", total);
			}
			else {
				snprintf(buf + strlen(buf), 100, "<br/><div style=\"font-weight: bold\">Non hai effettuato nessun acquisto.</div>");
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
	// prezzi smartphone
	prices.insert(make_pair("Samsung Galaxy", 500.0));
	prices.insert(make_pair("Apple iPhone", 800.0));
	prices.insert(make_pair("Huawei P", 200.0));
	prices.insert(make_pair("Sony Xperia", 250.0));

	// prezzi computer portatili
	prices.insert(make_pair("HP Pavilion", 1300.0));
	prices.insert(make_pair("Lenovo Thinkpad", 1200.0));
	prices.insert(make_pair("Fujitsu Lifebook", 1100.0));

	// prezzi televisori
	prices.insert(make_pair("Philips 22p", 150.0));
	prices.insert(make_pair("Philips 32p", 220.0));
	prices.insert(make_pair("Sony 32p", 380.0));
	prices.insert(make_pair("Samsung 49p", 600.0));
	prices.insert(make_pair("Sony 55p", 1200.0));

	struct mg_mgr eventManager;
	struct mg_connection *conn;

	mg_mgr_init(&eventManager);

	mg_http_listen(&eventManager, "http://localhost:8080", httpHandler, &eventManager);

	while (true) {
		mg_mgr_poll(&eventManager, 1000);
	}

	mg_mgr_free(&eventManager);
}

