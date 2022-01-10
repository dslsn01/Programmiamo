/*
file esercizio20.cpp 
compilare con: g++ -std=c++11 esercizio20.cpp
*/

#include <iostream>
#include <map>
#include <sqlite3.h>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::map;

int main()
{
	cout << "Cerca un film per titolo, anno, regista e attore principale." << endl;

	sqlite3 *db;
	sqlite3_stmt *res;
	sqlite3_open("videostore.db", &db);

	string query = "SELECT title, year, director, star FROM movies";
	map<string, string> params;

	cout << "Titolo del film: ";

	string title;
	getline(cin, title);

	if (!title.empty()) {
		params["title"] = title;
	}

	cout << "Anno: ";

	string year;
	getline(cin, year);

	if (!year.empty()) {
		params["year"] = year;
	}

	cout << "Regista: ";
	string director;
	getline(cin, director);

	if (!director.empty()) {
		params["director"] = director;
	}

	cout << "Attore principale: ";
	string star;
	getline(cin, star);

	if (!star.empty()) {
		params["star"] = star;
	}

	if (params.size() != 0) {
		int i = 0;
		for (auto& item : params) {
			string k = item.first;
			string clause = (i == 0) ? " WHERE " + k + " = ?" : " AND " + k + " = ?";
			query += clause;
			i++;
		}
	}

	int rc = sqlite3_prepare_v2(db, query.c_str(), -1, &res, NULL);

	if (rc != SQLITE_ERROR) {
		int j = 1;
		for (auto& item : params) {
			sqlite3_bind_text(res, j, item.second.c_str(), -1, SQLITE_STATIC);
			j++;
		}

		if (sqlite3_step(res) == SQLITE_DONE) {
			cout << "Film non disponibile in videoteca!" << endl;
			sqlite3_finalize(res);
			sqlite3_close(db);
			return 0;
		}

		do {
			cout << (const char*) sqlite3_column_text(res, 0) << ",";

			int yr = sqlite3_column_int(res, 1);
			if (yr != 0) cout << " (" << yr << ")";

			cout << " regista: " << (const char*) sqlite3_column_text(res, 2);

			const char *star = (const char*) sqlite3_column_text(res, 3);
			if (star != NULL) {
				cout << ", attore principale: " << star;
			}
			cout << "." << endl;
		}
		while (sqlite3_step(res) == SQLITE_ROW);
	}

	sqlite3_finalize(res);
	sqlite3_close(db);
}

