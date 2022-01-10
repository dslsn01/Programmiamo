/* file Person3.java */

class Person {
	private String name;
	private String surname;

	public Person(String name, String surname) {
		setName(name);
		setSurname(surname);
	}

	/* setter e getter del nome */

	public void setName(String name) {
		this.name = !name.isEmpty() ? name : "John";
	}

	public String getName() {
		return this.name;
	}

	/* setter e getter del cognome */

	public void setSurname(String surname) {
		this.surname = !surname.isEmpty() ? surname : "Doe";
	}

	public String getSurname() {
		return this.surname;
	}

	/* dichiarazione del metodo walk() */

	public void walk() {
		System.out.println(this.getName() + " " + this.getSurname() + " passeggia."); 
	}
}

class Env {
	public static void main(String [] args) {
		Person p = new Person("Walt", "Disney");
		p.walk();

		// nome e cognome vuoti non sono validi: vengono usati valori di default
		p = new Person("", "");
		p.walk();
	}
}

