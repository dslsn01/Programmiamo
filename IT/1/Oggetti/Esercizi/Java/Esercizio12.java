/* file Esercizio12.java */

/* gli "astronauti" sono tutti "persone": "Person" è la superclasse comune */

class Person {
	/* ogni persona ha un nome: la proprietà "nome" è dichiarata nella superclasse Person. */
	private String name;

	public Person(String name) {
		setName(name);
	}

	public String getName() {
		return this.name;
	}

	public void setName(String name) {
		this.name = name;
	}
}

interface Traveler {}

class Spaceman extends Person implements Traveler {
	public Spaceman(String name) {
		super(name);
	}

	public void floatInSpace() {
		System.out.println(this.getName() + " si muove nello spazio...");
	}

	@Override
	public String toString() {
		return "Sono l'astronauta " + this.getName() + "!";
	}
}

public class Esercizio12 {
	public static void main(String [] args) {
		Spaceman neil = new Spaceman("Neil Armstrong");

		if (neil instanceof Person) {
			System.out.println("L'astronauta " + neil.getName() + " è una persona!");
		}

		if (neil instanceof Traveler) {
			System.out.println("L'astronauta " + neil.getName() + " è un viaggiatore!");
		}
	}
}

