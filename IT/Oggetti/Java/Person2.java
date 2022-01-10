/* file Person2.java */

class Person {
	/* definizione dei campi "name" e "surname" */
	public String name;
	public String surname;

	/* definizione del costruttore della classe, che inizializza "name" e "surname" */
	public Person(String name, String surname) {
		this.name = name;
		this.surname = surname;
	}
}

/* la classe Env contiene il main() da cui inizia l'esecuzione del programma */	

class Env {
	public static void main(String [] args) {
		/* crea un oggetto di tipo "persona" */
		Person p = new Person("John", "Doe");
		System.out.println("Il nostro uomo si chiama " + p.name + " " + p.surname + ".");
	}
}

