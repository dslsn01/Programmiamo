/* file StaticMembers.java */

class IPad {
	/* dichiara un campo statico */
	private static int counter = 0;
	private String model;

	public static int getCounter() {
		return counter;
	}

	public IPad(String model) {
		setModel(model);
		counter++;
	}

	public void setModel(String model) {
		this.model = model;
	}

	public String getModel() {
		return this.model;
	}
}

public class StaticMembers {
	public static void main(String [] args) {
		IPad ipad1 = new IPad("Apple IPad Pro");
		IPad ipad2 = new IPad("Apple IPad Mini 2");
		IPad ipad3 = new IPad("Apple IPad Air");

		System.out.println("Prodotto " + ipad1.getModel() + ".");
		System.out.println("Prodotto " + ipad2.getModel() + ".");
		System.out.println("Prodotto " + ipad3.getModel() + ".");

		System.out.println("Sono stati prodotti " + IPad.getCounter() + " pezzi in totale.");
	}
}

