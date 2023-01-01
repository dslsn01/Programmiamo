/*
file esercizio6.cpp
compilare con: g++ -std=c++11 esercizio6.cpp
*/

#include <iostream>
#include <array>
#include <stdexcept>

using std::cout;
using std::cerr;
using std::endl;
using std::array;
using std::logic_error;

class Baz {
	public:
		virtual void baz() = 0;
};

class Foo : public Baz {
	public:
		void baz() override;
};

void Foo::baz() {
	cout << "Foo" << endl;
}

class Bar : public Baz {
	public:
		void baz() override;
};

void Bar::baz() {
	throw logic_error("Operazione non supportata!");
}

int main()
{
	array<Baz*, 3> objs = {new Foo(), new Bar(), new Foo()};

	for (const auto &obj : objs) {
		try {
			obj->baz();
		}
		catch (logic_error& e) {
			cerr << e.what() << endl;
		}
	}

	cout << "Fine del programma." << endl;
}

