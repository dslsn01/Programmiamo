/* file templateObj.cpp */

#include <iostream>

using std::string;
using std::cout;
using std::endl;
using std::ostream;

/* la classe generica GBox può contenere un regalo qualsiasi */

template<typename T>
class GBox {
	/* il tipo del parametro generico viene stabilito durante la compilazione */
	private:
		T gift;

	public:
		GBox(T gift);
		T unpack();
};

template<typename T>
GBox<T>::GBox(T gift) {
	this->gift = gift;
}

template<typename T>
T GBox<T>::unpack() {
	return this->gift;
}

class Toy {
	friend ostream& operator<<(ostream &os, const Toy &);
};

class Holiday {
	friend ostream& operator<<(ostream &os, const Holiday &);
};

/* ridefinisce l'operatore "<<" per stampare comodamente il tipo dei regali sulla console */

ostream& operator<<(ostream &os, const Toy&) {
	os << "giocattolo";
	return os;
}

ostream& operator<<(ostream &os, const Holiday&) {
	os << "buono vacanza";
	return os;
}

int main()
{
	/* crea un pacco regalo per contenere un giocattolo */

	Toy toy;
	GBox<Toy> gift1(toy);

	/* crea un pacco regalo per contenere un buono vacanza */

	Holiday holiday;
	GBox<Holiday> gift2(holiday);

	cout << "Ti regalo un " << gift1.unpack() << "!" << endl;
	cout << "Ti regalo un " << gift2.unpack() << "!" << endl;
}

