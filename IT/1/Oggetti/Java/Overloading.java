/* file Overloading.java */

class Person {
	/* sono stati definiti due metodi con lo stesso nome e differente lista di argomenti */

	public void foo() {
		System.out.println("Ciao, mondo!");
	}

	public void foo(String name) {
		System.out.println("Ciao, " + name + "!");
	}
}

class Env {
	public static void main(String [] args) {
		Person person = new Person();

		person.foo();
		person.foo("John Doe");
	}
}

