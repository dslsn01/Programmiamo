/* file StringSearch.java */

public class StringSearch {
	public static void main(String [] args) {
		String s = "Cantami, o Diva, del pelide Achille l'ira funesta";

		int indexA = s.indexOf('A');
		System.out.println("Indice di 'A': " + indexA);

		int indexZ = s.indexOf('Z');
		System.out.println("Indice di 'Z': " + indexZ);

		int indexAchille = s.indexOf("Achille");
		System.out.println("Indice della parola 'Achille': " + indexAchille); 
	}
}

