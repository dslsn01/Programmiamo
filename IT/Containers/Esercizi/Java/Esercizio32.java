/* file Esercizio32.java */

import java.io.Console;
import java.util.Map;
import java.util.Map.Entry;
import java.util.HashMap;
import java.util.List;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class Esercizio32 {
	public static void main(String [] args) {
		Map<String, String> students = new HashMap<String, String>();

		students.put("A23234", "Mario Rossi");
		students.put("A01357", "Luigi Bianchi");
		students.put("A12579", "Giovanni Verdi");

		Map<String, Integer> grades = new HashMap<String, Integer>();

		Console console = System.console();

		System.out.println("Risultati prova d'esame");

		for (Entry<String, String> student : students.entrySet()) {
			String s = console.readLine("Lo studente " + student.getValue() + " ha passato l'esame? s/n: ");

			if (s.equalsIgnoreCase("s")) {
				int grade = 0;

				while (grade == 0) {
					String v = console.readLine("Voto: ");
					if (v.isEmpty() || !v.matches("[\\d]{2}")) {
						System.out.println("Voto non valido!");
						continue;
					}

					grade = Integer.parseInt(v);
					if (grade < 18) {
						System.out.println("Voto non valido!");
						continue;
					}

					grades.put(student.getKey(), grade);
				}
			}
		}

		List<Entry<String, Integer>> arr = new ArrayList<Entry<String, Integer>>(grades.entrySet());

		Collections.sort(arr, new Comparator<Entry<String, Integer>>() {
			@Override
			public int compare(Entry<String, Integer> a, Entry<String, Integer> b) {
				return b.getValue().compareTo(a.getValue());
			}
		});

		for (Entry<String, Integer> grade : arr) {
			String matr = grade.getKey();
			System.out.println("Lo studente " + students.get(matr) + " ha superato l'esame finale con il voto " + grade.getValue() + ".");
		}

		if (arr.size() == students.size()) {
			System.out.println("Tutti gli studenti hanno passato la prova d'esame.");
			students.clear();
		}
		else {
			students.keySet().removeAll(grades.keySet());

			for (Entry<String, String> student : students.entrySet()) {
				System.out.println("Lo studente " + student.getValue() + " deve ancora sostenere la prova d'esame.");
			}
		}
	}
}

