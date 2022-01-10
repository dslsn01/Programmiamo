/* file Esercizio3.java */

class Spaceman {
	@Override
	public String toString() {
		return "Sono un astronauta!";
	}
}

public class Esercizio3 {
	public static void main(String [] args) {
		Spaceman neil = new Spaceman();

		// cosa stampa?
		System.out.println(neil);
	}
}

