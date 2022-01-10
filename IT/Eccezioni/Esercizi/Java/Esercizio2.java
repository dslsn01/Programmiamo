/* file Esercizio2.java */

public class Esercizio2 {
	public static void main(String [] args) {
		String [] arr = {"United", "States", "", "America"};

		for (String s : arr) {
			try {
				System.out.print(s.charAt(0));
			}
			catch (StringIndexOutOfBoundsException e) {}
		}

		System.out.print(System.lineSeparator());
		System.out.println("Fine del programma.");
	}
}

