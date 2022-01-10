/* file TestOverride.java */

class Animal {
	/* definizione originale del metodo foo() */
	public void foo() {
		System.out.println("Ciao, sono un animale!");
	}
}

class Person extends Animal {
	/* override del metodo foo() ereditato dalla superclasse Animal */
	@Override
	public void foo() {
		System.out.println("Ciao, sono una persona!");
	}
}

public class TestOverride {
	public static void main(String [] args) {
		/* crea un'istanza della superclasse Animal */

		Animal a = new Animal();

		/* ...invoca il metodo foo() definito nella classe Animal */

		a.foo();

		/* crea un'istanza della sottoclasse 'Person' */

		Person p = new Person();

		/* ...invoca il metodo foo() ridefinito nella classe Person */

		p.foo();
	}	
}

