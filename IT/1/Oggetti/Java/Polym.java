/* file Polym.java */

/* dichiara il campo "age" nella superclasse Animal */
class Animal {
	private int age;

	public Animal(int age) {
		setAge(age);
	}

	public int getAge() {
		return this.age;
	}

	public void setAge(int age) {
		this.age = age;
	}
}

/* la classe Person estende la classe Animal ed eredita i suoi membri */

class Person extends Animal {
	private String name;
	private String surname;

	public Person(String name, String surname, int age) {
		super(age);
		this.setName(name);
		this.setSurname(surname);
	}

	public String getName() {
		return this.name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getSurname() {
		return this.surname;
	}

	public void setSurname(String surname) {
		this.surname = surname;
	}

	@Override
	public String toString() {
		return this.name + " " + this.surname + ", " + this.getAge() + " anni.";
	}
}

class Env {
	public static void main(String [] args) {
		/* crea un'istanza della sottoclasse Person */

		Person p = new Person("John", "Doe", 30);

		/* verifica che p appartenga al tipo Person, ...ma anche al tipo Animal */

		System.out.println("p animale? " + (p instanceof Animal));
		System.out.println("p persona? " + (p instanceof Person));

		// stampa l'oggetto con il metodo toString()
		System.out.println(p);
	}
}

