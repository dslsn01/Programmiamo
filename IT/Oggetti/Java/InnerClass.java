/* file InnerClass.java */

import java.util.Random;

/* la classe Sprinkler rappresenta un sistema antincendio */
class Sprinkler {
	/* la classe HeatDetector rappresenta un sistema di rilevamento temperatura */
	private class HeatDetector {
		/* se la temperatura supera i 70 gradi C, potrebbe esserci un incendio */
		public boolean heatControl(int ht) {
			System.out.println("Temperatura rilevata: " + ht + " gradi C.");
			return ht >= 70 ? true : false;
		}
	} // fine della classe innestata

	/* Il sistema antincendio possiede un rilevatore di temperatura interno */
	private HeatDetector heatDetector = new HeatDetector();

	/* controlla la temperatura, e nel caso suona l'allarme */
	public boolean fire(int ht) {
		boolean fire = this.heatDetector.heatControl(ht);
		if (fire == true) {
			System.out.println("Possibile incendio!\nI passeggeri sono invitati a raggiungere l'uscita di sicurezza.");
		}
		return fire;
	}
}

public class InnerClass {
	public static void main(String [] args) {
		Sprinkler sprinkler = new Sprinkler();
		Random rand = new Random();

		/* controlla periodicamente la temperatura della metropolitana */

		int min = 18;
		int max = 100;

		while (true) {
			int ht = rand.nextInt((max-min)+1) + min;
			if (sprinkler.fire(ht) == true) {
				break;
			}
		}
	}
}

