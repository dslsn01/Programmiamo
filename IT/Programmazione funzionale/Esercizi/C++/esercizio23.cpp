/*
file esercizio23.cpp
compilare con: g++ -std=c++11 esercizio23.cpp
*/

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <ctime>
#include <iomanip>

using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::vector;
using std::istringstream;
using std::get_time;

struct Person {
	string n;
	string sn;
	string dt;
};

int main() {
	vector<Person> b = {{"John", "Doe", "01/09/1995"}, {"Jane", "Doe", "31/12/2000"}, {"Joe", "Bloggs", "01/05/2010"}, {"Mario", "Rossi", "01/09/1980"}, {"Luigi", "Bianchi", "01/01/1970"}, {"Giovanni", "Verdi", "01/11/1985"}};

	struct tm bd = {0};
	time_t now = time(nullptr);
	// 18 anni fa
	struct tm *tm1 = localtime(&now);
	tm1->tm_year -= 18;
	// normalizza la data
	mktime(tm1);

	vector<Person> b2;

	copy_if(b.begin(), b.end(), inserter(b2, b2.begin()), [&] (const Person& p) {
		struct tm td = {0};
		istringstream ss(p.dt);
		ss >> get_time(&td, "%d/%m/%Y");

		time_t x = mktime(&td);	// data di nascita
		time_t y = mktime(tm1); // 18 anni fa
		return difftime(y, x) > 0;
	});

	vector<Person> li(b2.size());

	partial_sort_copy(b2.begin(), b2.end(), li.begin(), li.end(), [] (const Person& p1, const Person& p2) {
		return p1.n < p2.n;
	});

	vector<string> s;

	transform(li.begin(), li.end(), inserter(s, s.begin()), [] (const Person& p) {
		time_t now = time(nullptr);
		struct tm *today = localtime(&now);
		struct tm td = {0};
		istringstream ss(p.dt);
		ss >> get_time(&td, "%d/%m/%Y");

		time_t x = mktime(&td);
		time_t y = mktime(today);
		double diff = difftime(y, x) / (60 * 60 * 24);
		string sdiff = to_string(diff / 365);
		return p.n + " " + p.sn + " (" + sdiff.substr(0, sdiff.find(".") + 2) + " anni)";
	});

	string str = accumulate(s.begin(), s.end(), string(), [] (string& result, const string& b) {
		return !result.empty() ? result + "\n" + b : b;
	});

	cout << str << endl;
}

