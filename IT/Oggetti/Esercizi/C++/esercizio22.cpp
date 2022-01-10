/*
file esercizio22.cpp
compilare con: g++ -std=c++11 esercizio22.cpp
*/

#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::ostream;

class Animal {
	public:
		virtual ~Animal();
		virtual void spec() = 0;
};

// le classi polimorfe devono avere un distruttore virtuale!
Animal::~Animal() {}

class Cat : public Animal {
	public:
		void spec() override;
};

void Cat::spec() {
	cout << "gatto" << endl;
}

class Dog : public Animal {
	public:
		void spec() override;
};

void Dog::spec() {
	cout << "cane" << endl;
}

class Cow : public Animal {
	public:
		void spec() override;
};

void Cow::spec() {
	cout << "mucca" << endl;
}

class Factory {
	public:
		Animal* getAnimal(string animal);
};

Animal* Factory::getAnimal(string animal) {
	if ("gatto" == animal) {
		return new Cat();
	}
	if ("cane" == animal) {
		return new Dog();
	}
	if ("mucca" == animal) {
		return new Cow();
	}

	return NULL;
}

int main()
{
	Factory factory;
	Animal *animal = NULL;

	animal = factory.getAnimal("gatto");
	animal->spec();
	delete animal;

	animal = factory.getAnimal("cane");
	animal->spec();
	delete animal;

	animal = factory.getAnimal("mucca");
	animal->spec();
	delete animal;
}

