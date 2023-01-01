/* file Esercizio4.java */

class Spaceman {
	private String name;

	public Spaceman(String name) {
		this.name = name;
	}

	@Override
	public String toString() {
		return "Sono l'astronauta " + this.name + "!";
	}
}

public class Esercizio4 {
	public static void main(String [] args) {
		Spaceman neil = new Spaceman("Neil Armstrong");

		// cosa stampa?
		System.out.println(neil);
	}
}

