/* file Serialization2.java */

import java.io.Serializable;
import java.io.ObjectOutputStream;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;

class Sword implements Serializable {
	private String name;

	public Sword(String name) {
		this.name = name;
	}

	@Override
	public String toString() {
		return this.name;
	}
}

/* la classe Highlander, serializzabile, contiene quale membro un oggetto del tipo Sword, a sua volta serializzabile */

class Highlander implements Serializable {
	private Sword sword;

	public Highlander(Sword sword) {
		this.setSword(sword);
	}

	public Sword getSword() {
		return this.sword;
	}

	public void setSword(Sword sword) {
		this.sword = sword;
	}
}

public class Serialization2 {
	public static void main(String [] args) {
		Highlander highlander = new Highlander(new Sword("Excalibur"));
		System.out.println("Spada prima della serializzazione: " + highlander.getSword());
		
		try {
			FileOutputStream fos = new FileOutputStream("highlander.ser");
			ObjectOutputStream oos = new ObjectOutputStream(fos);
			oos.writeObject(highlander);
			oos.close();

			FileInputStream fis = new FileInputStream("highlander.ser");
			ObjectInputStream ois = new ObjectInputStream(fis);
			Highlander restored = (Highlander)ois.readObject();
			Sword sword = restored.getSword();
			System.out.println("Spada dopo la serializzazione: " + sword);

		}
		catch (FileNotFoundException e) { e.printStackTrace(); }
		catch (IOException e) { e.printStackTrace(); }
		catch (ClassNotFoundException e) { e.printStackTrace(); }
	}
}

