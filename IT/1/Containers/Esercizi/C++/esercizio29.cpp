/*
file esercizio29.cpp
compilare con: g++ -std=c++11 esercizio29.cpp
*/

#include <iostream>
#include <map>

using std::cout;
using std::endl;
using std::string;
using std::map;

int main()
{
	map<int, string> colors = {{1, "rosso"}, {2, "verde"}, {3, "blu"}, {4, "giallo"}, {5, "ciano"}, {6, "magenta"}, {7, "arancio"}, {8, "viola"}, {9, "bianco"}, {10, "nero"}};

	cout << "Colori = {";

	for (auto& col : colors) {
		cout << col.first << "=" << col.second << ", ";
	}

	cout << "\b\b}" << endl;

	map<int, string> rgb(colors.find(1), colors.find(4));
	map<int, string> cmy(colors.find(4), colors.find(7));
	map<int, string> tc(colors.find(7), colors.find(9));
	map<int, string> nt(colors.find(9), colors.end());

	cout << "Colori primari = {";

	for (auto& col : rgb) {
		cout << col.first << "=" << col.second << ", ";
	}

	cout << "\b\b}" << endl;

	cout << "Colori secondari = {";

	for (auto& col : cmy) {
		cout << col.first << "=" << col.second << ", ";
	}

	cout << "\b\b}" << endl;

	cout << "Colori terziari = {";

	for (auto& col : tc) {
		cout << col.first << "=" << col.second << ", ";
	}

	cout << "\b\b}" << endl;

	cout << "Colori neutri = {";

	for (auto& col : nt) {
		cout << col.first << "=" << col.second << ", ";
	}

	cout << "\b\b}" << endl;
}

