/* file Esercizio20.java */

import java.util.Map;
import java.util.HashMap;
import java.util.Arrays;

/* la classe Employee rappresenta un'impiegato di un'azienda */

class Employee {
	/* identifichiamo ogni impiegato da nome, cognome e numero di badge */
	private String name;
	private String surname;
	private int badge;

	public Employee(String name, String surname, int badge) {
		this.name = name;
		this.surname = surname;
		this.badge = badge;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getName() {
		return this.name;
	}

	public void setSurname(String surname) {
		this.surname = surname;
	}

	public String getSurname() {
		return this.surname;
	}

	public void setBadge(int badge) {
		this.badge = badge;
	}

	public int getBadge() {
		return this.badge;
	}

	/* il metodo toString() stampa nome, cognome e bagde dell'impiegato corrente */
	@Override
	public String toString() {
		return this.name + " " + this.surname + ", badge numero=" + this.badge;
	}

	/* due impiegati sono uguali se e solo se hanno lo stesso badge, quindi sono la stessa persona */
	@Override
	public boolean equals(Object obj) {
		if (!(obj instanceof Employee)) {
			return false;
		}
		Employee other = (Employee)obj;
		boolean result = (this.badge == other.getBadge());

		return result;
	}
	
	/* il metodo hashCode() restituisce l'hash di tutti i campi */
	@Override
	public int hashCode() {
		/* calcola l'hash complessivo di tutti i campi, e moltiplica il risultato per una costante prima */
		final int prime = 31;
		int result = 1;
		String [] hash = new String[]{this.name, this.surname, String.valueOf(this.badge)};
		result = prime * result + Arrays.hashCode(hash);
		return result;
	}
}

public class Esercizio20 {
	public static void main(String [] args) {
		Employee emp1 = new Employee("Mario", "Rossi", 1000);
		Employee emp2 = new Employee("Luigi", "Bianchi", 1001);
		Employee emp3 = new Employee("Luigi", "Bianchi", 1001);

		System.out.println(emp1);
		System.out.println(emp2);
		System.out.println(emp3);

		System.out.println("Il primo e il secondo impiegato sono la stessa persona? " + (emp1.equals(emp2)));
		System.out.println("Il secondo e il terzo impiegato sono la stessa persona? " + (emp2.equals(emp3)));
	}
}

