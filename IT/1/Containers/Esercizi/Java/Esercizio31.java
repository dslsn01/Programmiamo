/* file Esercizio31.java */

import java.util.Map;
import java.util.Map.Entry;
import java.util.HashMap;
import java.util.List;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class Esercizio31 {
	public static void main(String [] args) {
		Map<String, String> students = new HashMap<String, String>();

		students.put("A23234", "Mario Rossi");
		students.put("A01357", "Luigi Bianchi");
		students.put("A12579", "Giovanni Verdi");

		Map<String, String> cdl = new HashMap<String, String>();

		cdl.put("A12579", "Informatica");
		cdl.put("A01357", "Matematica");
		cdl.put("A23234", "Fisica");

		System.out.println("Studenti del corso");

		List<Entry<String, String>> arr = new ArrayList<Entry<String, String>>(students.entrySet());

		Collections.sort(arr, new Comparator<Entry<String, String>>() {
				@Override
				public int compare(Entry<String, String> a, Entry<String, String> b) {
					return a.getValue().compareTo(b.getValue());
				}
			}
		);

		for (Entry<String, String> entry : arr) {
			String matr = entry.getKey();
			System.out.println("Matricola " + matr + ", " + entry.getValue() + ", corso di laurea in " + cdl.get(matr) + ".");
		}
	}
}

