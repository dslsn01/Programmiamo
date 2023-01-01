/* file Esercizio5.java */

class Spaceman {
	private String name;

	public Spaceman(String name) {
		setName(name);
	}

	public String getName() {
		return this.name;
	}

	public void setName(String name) {
		this.name = name;
	}

	@Override
	public String toString() {
		return "Sono l'astronauta " + this.name + "!";
	}
}

public class Esercizio5 {
	public static void main(String [] args) {
		Spaceman neil = new Spaceman("Neil Armstrong");
		System.out.println(neil);
	}
}

