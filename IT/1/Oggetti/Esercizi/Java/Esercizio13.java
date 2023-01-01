/* file Esercizio13.java */

/* "astronauti" e "passeggeri" sono tutti "persone": "Person" è la superclasse comune */

class Person {
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

class Spaceman extends Person {
	public Spaceman(String name) {
		super(name);
	}
}

class Passenger extends Person {
	public Passenger(String name) {
		super(name);
	}
}

class Spaceshuttle {
	public void welcome(Person passenger) {
		System.out.println("Benvenuto sullo shuttle, " + passenger.getName() + "!");
	}
}

public class Esercizio13 {
	public static void main(String [] args) {
		Person buzz = new Spaceman("Buzz Aldrin");
		Person neil = new Spaceman("Neil Armstrong");
		Person jBloggs = new Passenger("Joe Bloggs");

		Spaceshuttle shuttle = new Spaceshuttle();

		/* il metodo welcome() dello Spaceshuttle può ricevere una persona generica */
		shuttle.welcome(buzz);
		shuttle.welcome(neil);
		shuttle.welcome(jBloggs);
	}
}

