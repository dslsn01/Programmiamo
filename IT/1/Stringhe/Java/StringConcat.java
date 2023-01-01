/* file StringConcat.java */

public class StringConcat {
	public static void main(String [] args) {
		String hello = "Ciao, ";
		String world = "mondo!";

		/* concatena le due stringhe, usando l'operatore "+" */

		String s1 = hello + world;
		System.out.println(s1);

		/* ...o il metodo String.concat() */

		String s2 = hello.concat(world);
		System.out.println(s2);

		if (s1.equals(s2)) {
			System.out.println("Le stringhe \"" + s1 + "\" e \"" + s2 + "\" sono uguali.");
		}

		int n = 1;
		String s3 = " è un numero positivo.";

		/* concatena le due stringhe: il numero 1 viene automaticamente convertito in una stringa */

		System.out.println(n + s3);
	}
}

