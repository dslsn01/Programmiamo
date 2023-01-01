/* file Deserialization.java */

import java.io.ObjectInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;

public class Deserialization {
	public static void main(String [] args) {
		try {
			/* legge l'oggetto serializzato nel file e ripristina l'oggetto originale */

			FileInputStream fis = new FileInputStream("player.ser");
			ObjectInputStream ois = new ObjectInputStream(fis);
			Player player = (Player) ois.readObject();

			System.out.println("Giocatore ripristinato con successo. \nPunteggio di " + player.getName() + " dopo il ripristino: " + player.getScore());
			ois.close();

		} 
		catch (FileNotFoundException e) { e.printStackTrace(); }
		catch (ClassNotFoundException e) { e.printStackTrace(); }
		catch (IOException e) { e.printStackTrace(); }
	}
}

