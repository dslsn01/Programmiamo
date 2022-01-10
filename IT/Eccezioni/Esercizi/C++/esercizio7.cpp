/*
file esercizio7.cpp
compilare con: g++ -std=c++11 esercizio7.cpp
*/

#include <iostream>
#include <array>
#include <stdexcept>

using std::cout;
using std::cerr;
using std::endl;
using std::array;
using std::runtime_error;
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
	array<Baz*, 4> objs = {new Foo(), nullptr, new Bar(), new Foo()};

	for (const auto &obj : objs) {
		try {
			if (obj == nullptr) {
				throw runtime_error("Oggetto nullo!");
			}
			else {
				obj->baz();
			}
		}
		catch (logic_error& e) {
			cerr << e.what() << endl;
		}
		catch (runtime_error& e) {
			cerr << e.what() << endl;
		}
	}

	cout << "Fine del programma." << endl;
}

