/* file Types.java */

public class Types {
	public static void main(String [] args) {
		String s = System.console().readLine("Quanti anni hai? ");

		/* controlla che sia stato digitato un numero */

		if (!s.matches("[\\d]+")) {
			System.out.println("Numero non valido!");
			return;
		}

		/* converte gli anni da stringa a numero intero con Integer.parseInt() */
		int age = Integer.parseInt(s);

		if (age >= 18) {
			System.out.println("Puoi prendere la patente.");
		}
		else {
			System.out.println("Non puoi ancora prendere la patente!");
		}
	}
}

