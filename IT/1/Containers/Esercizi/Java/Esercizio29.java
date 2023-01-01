/* file Esercizio29.java */

import java.util.Map;
import java.util.NavigableMap;
import java.util.TreeMap;

public class Esercizio29 {
	public static void main(String [] args) {
		// mappa ordinata che posiziona le coppie chiave/valore in base alla chiave
		NavigableMap<Integer, String> colors = new TreeMap<Integer, String>();

		colors.put(1, "rosso");
		colors.put(2, "verde");
		colors.put(3, "blu");
		colors.put(4, "giallo");
		colors.put(5, "ciano");
		colors.put(6, "magenta");
		colors.put(7, "arancio");
		colors.put(8, "viola");
		colors.put(9, "bianco");
		colors.put(10, "nero");

		System.out.println("Colori = " + colors);

		int k = 1;
		Map<Integer, String> rgb = colors.subMap(k, k += 3);
		Map<Integer, String> cmy = colors.subMap(k, k += 3);
		Map<Integer, String> tc = colors.subMap(k, k += 2);
		Map<Integer, String> nc = colors.subMap(k, k += 2);

		System.out.println("Colori primari = " + rgb);
		System.out.println("Colori secondari = " + cmy);
		System.out.println("Colori terziari = " + tc);
		System.out.println("Colori neutri = " + nc);
	}
}

