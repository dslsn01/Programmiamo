/* file Esercizio23.java */

import java.time.LocalDate;
import java.time.Period;
import java.time.format.DateTimeFormatter;
import java.util.List;
import java.util.stream.Stream;
import java.util.stream.Collectors;

public class Esercizio23 {
	private static class Person {
		public String n;
		public String sn;
		public String dt;

		public Person(String n, String sn, String dt) {
			this.n = n;
			this.sn = sn;
			this.dt = dt;
		}
	}

	public static void main(String [] args) {
		Person [] b = new Person[] { new Person("John", "Doe", "01/09/1995"), new Person("Jane", "Doe", "31/12/2000"), new Person("Joe", "Bloggs", "01/05/2010"), new Person("Mario", "Rossi", "01/09/1980"), new Person("Luigi", "Bianchi", "01/01/1970"), new Person("Giovanni", "Verdi", "01/11/1985") };

		// data di 18 anni fa
		LocalDate ma = LocalDate.now().minusYears(18);

		// seleziona tutti gli individui maggiorenni

		List<Person> li = Stream.of(b).filter(p -> {
			LocalDate bd = LocalDate.parse(p.dt, DateTimeFormatter.ofPattern("d/MM/yyyy"));
			return Period.between(bd, ma).getYears() >= 0;
		})
		.sorted((p1, p2) -> {
			return p1.n.compareTo(p2.n);
		})
		.collect(Collectors.toList());

		String s = li.stream().map(p -> {
			LocalDate bd = LocalDate.parse(p.dt, DateTimeFormatter.ofPattern("d/MM/yyyy"));
			Period interval = Period.between(bd, LocalDate.now());
			int m = interval.getMonths();
			String res = p.n + " " + p.sn + " (" + interval.getYears() + " anni";
			if (m > 0) res += ", " + m + " mesi";
			res += ")";
			return res;
		})
		.map(Object::toString).collect(Collectors.joining(System.lineSeparator()));

		System.out.println(s);
	}
}

