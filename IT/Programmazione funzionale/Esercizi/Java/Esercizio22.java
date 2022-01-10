/* file Esercizio22.java */

import java.util.List;
import java.util.stream.Stream;
import java.util.stream.Collectors;

public class Esercizio22 {
	private static class Title {
		public String title;
		public String auth;
		public Integer yr;

		public Title(String title, String auth, int yr) {
			this.title = title;
			this.auth = auth;
			this.yr = yr;
		}
	}

	public static void main(String [] args) {
		Title [] b = new Title[] { new Title("De Arte Combinatoria", "Gottfried Wilhelm Leibniz", 1666), new Title("Discorso sulla Metafisica", "Gottfried Wilhelm Leibniz", 1686), new Title("Sulla strada", "Jack Kerouac", 1957), new Title("Il Libro dei Sogni", "Jack Kerouac", 1960), new Title("Sessanta racconti", "Dino Buzzati", 1958), new Title("Il deserto dei Tartari", "Dino Buzzati", 1940), new Title("Un amore", "Dino Buzzati", 1963), new Title("Zanna bianca", "Jack London", 1906) };

		List<Title> li = Stream.of(b).filter(t -> t.auth.equals("Dino Buzzati")).sorted((m, n) -> {
			return n.yr.compareTo(m.yr);
		}).collect(Collectors.toList());

		String s = li.stream().map(p -> "\"" + p.title + "\", " + p.auth + " (" + String.valueOf(p.yr) + ")").map(Object::toString).collect(Collectors.joining(System.lineSeparator()));

		System.out.println(s);
	}
}

