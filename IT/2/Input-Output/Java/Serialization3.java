/* file Serialization3.java */

import java.io.Serializable;
import java.io.ObjectOutputStream;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;

/* la classe Hat non implementa l'interfaccia Serializable */

class Hat {
	private String color;

	public Hat(String color) {
		setColor(color);
	}

	public void setColor(String color) {
		this.color = color;
	}

	public String getColor() {
		return this.color;
	}
}

/* la classe Clown, serializzabile, contiene un membro non serializzabile di tipo Hat */

class Clown implements Serializable {
	private transient Hat hat;

	public Clown(Hat hat) {
		setHat(hat);
	}

	public void setHat(Hat hat) {
		this.hat = hat;
	}

	public Hat getHat() {
		return this.hat;
	}

	private void writeObject(ObjectOutputStream oos) throws IOException {
		oos.defaultWriteObject();
		oos.writeObject(hat.getColor());
	}

	private void readObject(ObjectInputStream ois) throws IOException, ClassNotFoundException {
		ois.defaultReadObject();
		hat = new Hat((String)ois.readObject());
	}
}

public class Serialization3 {
	public static void main(String [] args) {
		try {

			Clown clown = new Clown(new Hat("rosso"));
			System.out.println("Prima della serializzazione, il cappello del pagliaccio è di colore " + clown.getHat().getColor()); 

			FileOutputStream fos = new FileOutputStream("clown.ser");
			ObjectOutputStream oos = new ObjectOutputStream(fos);
			oos.writeObject(clown);
			oos.close();

			FileInputStream fis = new FileInputStream("clown.ser");
			ObjectInputStream ois = new ObjectInputStream(fis);
			Clown clown2 = (Clown)ois.readObject();
			ois.close();
		
			System.out.println("Dopo la serializzazione, il cappello del pagliaccio è di colore " + clown2.getHat().getColor());

		}
		catch (FileNotFoundException e) { e.printStackTrace(); }
		catch (IOException e) { e.printStackTrace(); }
		catch (ClassNotFoundException e) { e.printStackTrace(); }
	}
}

