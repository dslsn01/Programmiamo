/* file Esercizio18.java */

import java.util.List;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

class Employee implements Comparable<Employee> {
	private String matr;
	private String name;
	private String surname;

	public Employee(String matr, String name, String surname) {
		this.setMatr(matr);
		this.setName(name);
		this.setSurname(surname);
	}

	public String getMatr() {
		return this.matr;
	}

	public void setMatr(String matr) {
		this.matr = matr;
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

	public int compareTo(Employee e) {
		return this.matr.compareTo(e.getMatr());
	}

	@Override
	public String toString() {
		return matr + ", " + name + " " + surname;
	}
}

public class Esercizio18 {
	public static void main(String [] args) {
		List<Employee> ibm = new ArrayList<Employee>();

		ibm.add(new Employee("0010", "John", "Von Neumann"));
		ibm.add(new Employee("0011", "Gene", "Amdahl"));
		ibm.add(new Employee("0001", "Thomas", "Watson"));
		ibm.add(new Employee("0101", "Bob", "Bemer"));
		ibm.add(new Employee("0100", "John", "Backus"));

		System.out.println("Lista originale:");
		System.out.println(ibm);

		System.out.println("Ordinata per matricola:");

		Collections.sort(ibm);
		System.out.println(ibm);

		System.out.println("Ordinata per cognome:");

		Collections.sort(ibm, new Comparator<Employee>() {
			@Override
			public int compare(Employee a, Employee b) {
				return a.getSurname().compareTo(b.getSurname());
			}
		});

		System.out.println(ibm);

		System.out.println("Ordinata per nome e per cognome:");

		Collections.sort(ibm, new Comparator<Employee>() {
			@Override
			public int compare(Employee a, Employee b) {
				int c = a.getName().compareTo(b.getName());
				return c != 0 ? c : a.getSurname().compareTo(b.getSurname());
			}
		});

		System.out.println(ibm);
	}
}

