/* file Esercizio8.java */

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

	public void floatInSpace() {
		System.out.println(this.getName() + " si muove nello spazio...");
	}

	@Override
	public String toString() {
		return "Sono l'astronauta " + this.name + "!";
	}
}

class Pilot extends Spaceman {
	public Pilot(String name) {
		super(name);
	}

	@Override
	public String toString() {
		return "Sono il pilota " + this.getName();
	}
}

class Explorer extends Spaceman {
	public Explorer(String name) {
		super(name);
	}

	@Override
	public String toString() {
		return "Sono l'esploratore " + this.getName();
	}
}

public class Esercizio8 {
	public static void main(String [] args) {
		Pilot buzz = new Pilot("Buzz Aldrin");
		Explorer neil = new Explorer("Neil Armstrong");

		System.out.println(buzz);
		System.out.println(neil);
	}
}

