/* file Esercizio7.java */

public class Esercizio7 {
	public static void main(String [] args) {
		String s = "3.14159";
		String [] t = s.split("\\.");

		System.out.println("La parte intera di " + s + " è " + t[0] + ", mentre la parte decimale è 0." + t[1] + ".");
	}
}

