/* file test_namespace.cpp */

#include <iostream>
#include "Foo.h"

using std::cout;
using std::endl;
//using utils::Foo;

/* dichiarazione dello spazio dei nomi "mynamespace" */

namespace mynamespace {
	class Foo {
		public:
			void bar();
	};
}

/* implementazione della funzione membro della classe mynamespace::Foo */

void mynamespace::Foo::bar() 
{
	cout << "bar baz" << endl;
}

/* importa lo spazio dei nomi */

using namespace mynamespace;

int main() 
{
	Foo* foo1 = new Foo();
	foo1->bar();

	mynamespace::utils::Foo* foo2 = new mynamespace::utils::Foo();
	foo2->bar();
	
	delete foo1;
	delete foo2;
}
