/* file testVector2.cpp */

#include <iostream>
#include <iterator>
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::ostream_iterator;
using std::vector;

int main()
{
	/* crea un vettore di stringhe */

	vector<string> vect1;

	vect1.push_back("tigre");
	vect1.push_back("giraffa");
	vect1.push_back("elefante");
	vect1.push_back("zebra");
	vect1.push_back("coccodrillo");

	cout << "[";
	copy(vect1.begin(), vect1.end(), ostream_iterator<string>(cout, ", "));
	cout << "\b\b]" << endl;

	/* sezione di vettori */

	/* seleziona i primi tre elementi... */

	vector<string> sect1(vect1.begin(), vect1.begin()+3);

	cout << "[";
	copy(sect1.begin(), sect1.end(), ostream_iterator<string>(cout, ", "));
	cout << "\b\b]" << endl;

	/* ...gli ultimi due elementi, */

	vector<string> sect2(vect1.begin()+3, vect1.end());

	cout << "[";
	copy(sect2.begin(), sect2.end(), ostream_iterator<string>(cout, ", "));
	cout << "\b\b]" << endl;

	/* ...e gli elementi con indice da 1 a 3 */

	vector<string> sect3(vect1.begin()+1, vect1.begin()+4);

	cout << "[";
	copy(sect3.begin(), sect3.end(), ostream_iterator<string>(cout, ", "));
	cout << "\b\b]" << endl;

	vector<string> vect2;

	vect2.push_back("gnu");
	vect2.push_back("cane");
	vect2.push_back("lama");
	vect2.push_back("lupo");
	vect2.push_back("orso");
	vect2.push_back("cavallo");

	cout << "[";
	copy(vect2.begin(), vect2.end(), ostream_iterator<string>(cout, ", "));
	cout << "\b\b]" << endl;

	/* concatena i due vettori */

	vector<string> vect3;

	/* alloca la memoria necessaria per contenere tutti gli elementi dei due vettori iniziali */

	vect3.reserve(vect1.size() + vect2.size());

	vect3.insert(vect3.end(), vect1.begin(), vect1.end());
	vect3.insert(vect3.end(), vect2.begin(), vect2.end());

	cout << "[";
	copy(vect3.begin(), vect3.end(), ostream_iterator<string>(cout, ", "));
	cout << "\b\b]" << endl;
}

