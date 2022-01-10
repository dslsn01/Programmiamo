/* file Esercizio7.java */

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
}

class Explorer extends Spaceman {
	public Explorer(String name) {
		super(name);
	}
}

public class Esercizio7 {
	public static void main(String [] args) {
		Pilot buzz = new Pilot("Buzz Aldrin");
		Explorer neil = new Explorer("Neil Armstrong");

		System.out.println(buzz);
		System.out.println(neil);
	}
}

