/*
file esercizio31.cpp
compilare con: g++ -std=c++11 esercizio31.cpp
*/

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::pair;
using std::unordered_map;
using std::vector;
using std::sort;

bool comp(const pair<string, string>& p1, const pair<string, string>& p2) {
	return p1.second < p2.second;
}

int main()
{
	unordered_map<string, string> students = {{"A23234", "Mario Rossi"}, {"A01357", "Luigi Bianchi"}, {"A12579", "Giovanni Verdi"}};

	unordered_map<string, string> cdl = {{"A01357", "Matematica"}, {"A12579", "Informatica"}, {"A23234", "Fisica"}};

	cout << "Studenti del corso" << endl;

	/* la mappa non permette l'ordinamento, creiamo un vector per applicare l'ordinamento voluto */

	vector<pair<string, string>> vect(students.begin(), students.end());
	sort(vect.begin(), vect.end(), comp);

	for (auto& student : vect) {
		string matr = student.first;
		cout << "Matricola " << matr << ", " << student.second << ", corso di laurea in " << cdl[matr] << "." << endl;
	}
}

