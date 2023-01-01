/* file Esercizio11.java */

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
	public void floatInSpace() {
		System.out.println(this.getName() + " naviga nello spazio alla guida dello shuttle.");
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
	public void floatInSpace() {
		System.out.println(this.getName() + " galleggia nello spazio aperto...");
	}

	@Override
	public String toString() {
		return "Sono l'esploratore " + this.getName();
	}
}

class Spaceshuttle {
	public void welcome(Spaceman spaceman) {
		System.out.println("Benvenuto sullo shuttle, " + spaceman.getName() + "!");
	}
}

public class Esercizio11 {
	public static void main(String [] args) {
		Spaceman buzz = new Pilot("Buzz Aldrin");
		Spaceman neil = new Explorer("Neil Armstrong");

		Spaceshuttle shuttle = new Spaceshuttle();

		shuttle.welcome(buzz);
		shuttle.welcome(neil);
	}
}

