/* file Serialization.java */

import java.io.ObjectOutputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class Serialization {
	public static void main(String [] args) {
		Player player = new Player("Jimmy");

		/* incrementa il punteggio del giocatore */

		player.addScore(150);
		System.out.println("Punteggio di " + player.getName() + " prima della serializzazione: " + player.getScore());

		try {
			/* serializza l'oggetto salvandolo in un file binario */

			FileOutputStream fos = new FileOutputStream("player.ser");
			ObjectOutputStream oos = new ObjectOutputStream(fos);
			oos.writeObject(player);
			oos.close();

			System.out.println("Giocatore salvato su disco.");

		} catch (IOException e) {
			e.printStackTrace();
		} 
	}
}

