/* file Esercizio22.java */

/* l'interfaccia Animal identifica un animale generico */

interface Animal {
	public abstract void spec();
}

/* la classe Cat rappresenta un gatto */
class Cat implements Animal {
	@Override
	public void spec() {
		System.out.println("gatto");
	}
}

/* la classe Dog rappresenta un cane */
class Dog implements Animal {
	@Override
	public void spec() {
		System.out.println("cane");
	}
}

/* la classe Cow rappresenta una mucca */
class Cow implements Animal {
	@Override
	public void spec() {
		System.out.println("mucca");
	}
}

class Factory {
	public Animal getAnimal(String animal) {
		if ("gatto".equals(animal)) {
			return new Cat();
		}
		if ("cane".equals(animal)) {
			return new Dog();
		}
		if ("mucca".equals(animal)) {
			return new Cow();
		}

		return null;
	}
}

public class Esercizio22 {
	public static void main(String [] args) {
		Factory factory = new Factory();
		Animal animal = null;

		animal = factory.getAnimal("gatto");
		animal.spec();

		animal = factory.getAnimal("cane");
		animal.spec();

		animal = factory.getAnimal("mucca");
		animal.spec();
	}
}

