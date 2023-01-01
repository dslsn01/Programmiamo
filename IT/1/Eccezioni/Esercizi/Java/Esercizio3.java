/* file Esercizio3.java */

public class Esercizio3 {
	public static void main(String [] args) {
		String s = "Cantami, o Diva, del pelide Achille l'ira funesta";

		try {
			int i = 0;
			while (true) {
				System.out.print(s.charAt(i));
				i++;
			}
		}
		catch (StringIndexOutOfBoundsException e) {
			System.out.print(System.lineSeparator());
		}

		System.out.println("Fine del programma.");
	}
}

