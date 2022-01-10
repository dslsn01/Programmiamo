/*
file esercizio32.cpp
compilare con: g++ -std=c++11 esercizio32.cpp
*/

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::pair;
using std::unordered_map;
using std::set;
using std::vector;
// using std::stoi;
using std::inserter;
using std::set_intersection;

bool comp(const pair<string, int>& p1, const pair<string, int>& p2) {
	return p1.second > p2.second;
}

template<typename K, typename V>
string getKey(const pair<K, V>& pair) {
	return pair.first;
}

int main()
{
	unordered_map<string, string> students = {{"A23234", "Mario Rossi"}, {"A01357", "Luigi Bianchi"}, {"A12579", "Giovanni Verdi"}};

	unordered_map<string, int> grades;

	cout << "Risultati prova d'esame" << endl;

	for (auto& s : students) {
		cout << "Lo studente " << s.second << " ha passato l'esame? s/n: ";

		string c;
		getline(cin, c);

		if (c == "s") {
			int grade = 0;

			while (!grade) {
				cout << "Voto: ";
				string v;
				getline(cin, v);
				if (v.empty() || v.find_first_not_of("0123456789") != string::npos) {
					cout << "Voto non valido!" << endl;
					continue;
				}

				grade = stoi(v);

				if (grade < 18) {
					cout << "Voto non valido!" << endl;
					continue;
				}

				grades[s.first] = grade;
			}
		}
	}

	vector<pair<string, int>> vect(grades.begin(), grades.end());
	sort(vect.begin(), vect.end(), comp);

	for (auto& grade : vect) {
		string matr = grade.first;
		cout << "Lo studente " << students[matr] << " ha superato l'esame finale con il voto " << grade.second << "." << endl;
	}

	// se tutti gli studenti hanno passato l'esame
	if (vect.size() == students.size()) {
		students.clear();
		cout << "Tutti gli studenti hanno passato la prova d'esame." << endl;
	}
	else {
		set<string> sKeys;
		transform(students.begin(), students.end(), inserter(sKeys, sKeys.begin()), getKey<string, string>);

		set<string> gKeys;
		transform(grades.begin(), grades.end(), inserter(gKeys, gKeys.begin()), getKey<string, int>);

		set<string> commonKeys;
		set_intersection(sKeys.begin(), sKeys.end(), gKeys.begin(), gKeys.end(), inserter(commonKeys, commonKeys.begin()));

		for (string key : commonKeys) students.erase(key);

		for (auto& s : students) {
			cout << "Lo studente " << s.second << " deve ancora sostenere la prova d'esame." << endl;
		}
	}
}

