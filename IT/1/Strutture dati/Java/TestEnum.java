/* file TestEnum.java */

import java.util.Random;

enum Color {
	RED,
	YELLOW,
	GREEN
}

public class TestEnum {
	public static void main(String [] args) {
		/* inizializza casualmente il colore del semaforo */

		Random randomizer = new Random();
		int currentColor = randomizer.nextInt(3);

		/* mappa un intero al valore enumerazione appropriato */

		Color semaphore = Color.values()[currentColor];

		/* confronta il colore del semaforo con tutti i colori possibili */

		switch (semaphore)
		{
			case RED:
				System.out.println("Semaforo ROSSO: fermati!");
				break;
			case YELLOW:
				System.out.println("Semaforo GIALLO o lampeggiante: prudenza.");
				break;
			case GREEN:
				System.out.println("Semaforo VERDE: passa senza problemi...");
				break;
			default:
				System.out.println("Semaforo guasto?");
		}
	}
}

