/* file EmMultipleInheritance.java */

class Animal {
	public void walk() {
		System.out.println("Sto passeggiando.");
	}
}

/* dichiarazione dell'interfaccia Flyer */

interface Flyer {
	/* il metodo takeFlight() è dichiarato abstract, senza blocco di codice */

	public abstract void takeFlight();
}

/* la classe Person estende la classe Animal e implementa l'interfaccia Flyer */

class Person extends Animal implements Flyer {
	/* implementa il metodo takeFlight() definito nell'interfaccia */

	@Override
	public void takeFlight() {
		System.out.println("Sto decollando!");
	}
}

class Env {
	public static void main(String [] args) {
		Person p = new Person();

		/* verifica che p appartiene al tipo Animal */

		System.out.println("p è un animale? " + (p instanceof Animal));

		/* verifica che p appartiene anche al tipo interfaccia Flyer */

		System.out.println("p è un pilota di aereo? " + (p instanceof Flyer));

		p.walk();
		p.takeFlight();
	}
}

