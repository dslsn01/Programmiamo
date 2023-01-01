/* file MapFilterReduce.java */

import java.util.Collections;
import java.util.Locale;
import java.util.List;
import java.util.Random;
import java.util.stream.Collectors;

public class MapFilterReduce {
	public static void main(String [] args) {
		Random rand = new Random();
		List<Integer> v = rand.ints(200, 1, 100+1)
							  .boxed()
							  .collect(Collectors.toList());

		// converte tutti i voti in centesimi in voti in trentesimi

		List<Integer> li = v.stream()
							.map(n -> (int) Math.round((double) n*30/100))
							.collect(Collectors.toList());

		// seleziona tutti e soli gli studenti che hanno passato l'esame

		List<Integer> app = li.stream().filter(n -> n >= 18).collect(Collectors.toList());

		System.out.println("----- Voti sufficienti -----");

		System.out.println(app.stream()
							  .sorted(Collections.reverseOrder())
							  .collect(Collectors.toList()));

		System.out.println("-------- RIASSUNTO ---------");
		System.out.println(app.size() + " studenti su " + li.size() + " hanno passato la prova d'esame.");

		long bp = v.stream()
				  .map(n -> (int) Math.round((double) n*30/100))
				  .filter(n -> n >= 18)
				  .collect(Collectors.groupingBy(n -> n, Collectors.counting()))
				  .get(30);

		System.out.println(bp + " studenti hanno ottenuto il voto massimo.");

		// calcola il voto medio di superamento dell'esame

		double mv = app.stream().reduce(0, (m, n) -> m + n) / (double) app.size();
		System.out.println("Voto medio: " + String.format(Locale.ROOT, "%.1f", mv));
	}
}

