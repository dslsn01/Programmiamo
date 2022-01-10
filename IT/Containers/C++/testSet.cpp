/* 
file testSet.cpp
compilare con: g++ -std=c++11 testSet.cpp
*/

#include <iostream>
#include <iterator>
#include <set>

using std::string;
using std::cout;
using std::endl;
using std::ostream_iterator;
using std::set;

int main()
{
	/* dichiara un set di numeri interi: i numeri sono aggiunti in ordine casuale, ma il set li riordina automaticamente secondo l'ordinamento naturale */

	set<int> n = {2, 0, 1};

	cout << "N = [";
	copy(n.begin(), n.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;

	/* verifica la presenza dello zero nel set */

	if (n.count(0)) {
		cout << "L'insieme N include lo zero." << endl;
	}

	/* aggiunge il numero 3 al set */

	n.insert(3);

	/* scorre tutti gli elementi dell'insieme con un iteratore */

	cout << "N = [";

	for (auto it = n.begin(); it != n.end(); ++it) {
		cout << *it << ", ";
	}

	cout << "\b\b]" << endl;

	/* aggiunge i numeri 4, 5, 6, 7 al set */

	set<int> n2 = {4, 5, 6, 7};

	n.insert(n2.begin(), n2.end());

	cout << "N = [";
	copy(n.begin(), n.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;

	/* recupera il primo elemento (lo zero) dal set, con un iteratore */

	auto p = n.begin();
	cout << "Primo elemento di N: " << (*p) << endl;

	/* cancella il numero 7 dal set */

	n.erase(7);

	cout << "N = [";
	copy(n.begin(), n.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;

	/* cancella tutti gli elementi del set */

	n.clear();
	cout << "Cardinalità dell'insieme vuoto: " << n.size() << endl;
}

