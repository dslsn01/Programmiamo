/* file esercizio33.cpp */

#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::ostream;

class Submarine {
	public:
		template <typename T>
		void emb(const T& p);
};
template <typename T>
void Submarine::emb(const T& p) {
	cout << "Benvenuto a bordo, " << p << "!" << endl;
}

// marinaio
class Sailor {
	private:
		string name;

	public:
		Sailor(string name);

	friend ostream& operator<<(ostream& os, const Sailor& s);
};

Sailor::Sailor(string name) {
	this->name = name;
}

ostream& operator<<(ostream& os, const Sailor& s) {
	os << s.name;
	return os;
}

// passeggero
class Pass {
	private:
		string name;

	public:
		Pass(string name);

	friend std::ostream& operator<<(std::ostream&, const Pass&);
};

Pass::Pass(string name) {
	this->name = name;
}

ostream& operator<<(ostream& os, const Pass& p) {
	os << p.name;
	return os;
}

// cameriere
class Attn {
	private:
		string name;

	public:
		Attn(string name);

	friend std::ostream& operator<<(std::ostream&, const Attn&);
};

Attn::Attn(string name) {
	this->name = name;
}

ostream& operator<<(ostream& os, const Attn& a) {
	os << a.name;
	return os;
}

int main()
{
	Submarine nautilus;

	Sailor s("Capitano Nemo");
	Pass p1("Pierre Aronnax");
	Attn a("Conseil");
	Pass p2("Ned Land");

	nautilus.emb(s);
	nautilus.emb(p1);
	nautilus.emb(a);
	nautilus.emb(p2);
}

