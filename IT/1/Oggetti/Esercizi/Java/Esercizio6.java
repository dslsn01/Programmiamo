/* file Esercizio6.java */

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

	/* metodo che permette agli astronauti di muoversi nello spazio */
	public void floatInSpace() {
		System.out.println(this.getName() + " si muove nello spazio...");
	}

	@Override
	public String toString() {
		return "Sono l'astronauta " + this.name + "!";
	}
}

public class Esercizio6 {
	public static void main(String [] args) {
		Spaceman neil = new Spaceman("Neil Armstrong");
		neil.floatInSpace();
	}
}

