/* file TestNumber.java */

public class TestNumber {
	public static void main(String [] args) {
		String s = System.console().readLine("Digita un numero intero o in virgola mobile: ");

		/* controlla con due regex se "s" sia un numero intero/decimale */

		if (s.matches("^[0-9]+$")) {
			System.out.println(s + " è un numero intero.");
		}
		else if (s.matches("^[0-9]+\\.[0-9]{1,}$")) {
			System.out.println(s + " è un numero in virgola mobile.");
		}
		else {
			System.out.println("Attenzione! \"" + s + "\" non è un numero!");
		}
	}
}

