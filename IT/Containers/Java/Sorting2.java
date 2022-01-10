/* file Sorting2.java */

import java.util.List;
import java.util.ArrayList;
import java.util.Collections;

class Animal implements Comparable<Animal> {
	private String name = null;

	public Animal(String name) {
		setName(name);
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getName() {
		return this.name;
	}

	@Override
	public String toString() {
		return this.name;
	}
	
	public int compareTo(Animal other) {
		return this.name.compareTo(other.getName());
	}
}

public class Sorting2 {
	public static void main(String [] args) {
		/* crea una lista di animali */
		List <Animal>arr = new ArrayList<Animal>();

		arr.add(new Animal("tigre"));
		arr.add(new Animal("giraffa"));
		arr.add(new Animal("elefante"));

		System.out.println("Lista originale:");
		System.out.println(arr);

		Collections.sort(arr);

		System.out.println("Lista ordinata:");
		System.out.println(arr);
	}
}

