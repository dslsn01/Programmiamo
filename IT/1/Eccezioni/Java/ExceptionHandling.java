/* file ExceptionHandling.java */

public class ExceptionHandling {
	public static void main(String [] args) {
		int n = 5;
		int d = 0;

		/* inizio del blocco try ... catch */

		try {
			int q = n / d;
			System.out.println(q);
		}
		catch (ArithmeticException e) {
			// la clausola catch cattura l'eccezione
			e.printStackTrace();
		}

		System.out.println("Fine del programma.");
	}
}

