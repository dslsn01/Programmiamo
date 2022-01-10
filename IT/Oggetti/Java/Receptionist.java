/* file Receptionist.java */

import java.io.Console;

public class Receptionist {
	public static void main(String [] args) {
		System.out.println("Benvenuto nell'Hotel!");

		Console console = System.console();

		String n = console.readLine("Nome: ");
		String s = console.readLine("Cognome: ");

		System.out.println("Benvenuto, " + n + " " + s + "!");
	}
}

