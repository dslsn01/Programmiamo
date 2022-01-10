/* file CopyCtor.java */

import java.util.Map;
import java.util.Map.Entry;
import java.util.HashMap;

public class CopyCtor {
	private static class Student {
		private String name;
		private String matr;
		private String cdl;
		private HashMap<String, Integer> es;

		public Student(String name, String matr, String cdl) {
			this.name = name;
			this.matr = matr;
			this.cdl = cdl;
			this.es = new HashMap<String, Integer>() {{
				put("Architettura degli elaboratori", -1);
				put("Programmazione", -1);
				put("Calcolo 1", -1);
			}};
		}

		// nuovo costruttore di copia

		public Student(Student s) {
			this.name = s.name;
			this.matr = s.matr;
			this.cdl = s.cdl;
			this.es = new HashMap<String, Integer>(s.es);
		}

		public void unilib() {
			int _pass = 0;

			for (Map.Entry<String, Integer> p : this.es.entrySet()) {
				String k = p.getKey();
				Integer v = p.getValue(); 
				if (v != -1) {
					System.out.println(this.name + " (" + this.matr + ") ha superato l'esame \"" + k + "\" con il voto " + v + ".");
				_pass++;
				}
			}
		}

		@Override
		public String toString() {
			return this.name + ", matricola " + this.matr + ", corso di laurea in " + this.cdl + ".";
		}
	}

	public static void main(String [] args) {
		Student s1 = new Student("Mario Rossi", "A23234", "Scienze dell'Informazione");
		System.out.println(s1);

		// crea un nuovo studente con il costruttore di copia

		Student s2 = new Student(s1);

		s2.matr = "A01357";
		s2.cdl = "Ingegneria Informatica";
		s2.es.put("Programmazione", 30);

		System.out.println(s2);
		s1.unilib();
		s2.unilib();
	}
}

