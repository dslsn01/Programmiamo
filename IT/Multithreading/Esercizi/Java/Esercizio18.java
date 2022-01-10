/* file Esercizio18.java */

import java.util.concurrent.ThreadLocalRandom;
import java.util.concurrent.Semaphore;

class VendingMachine {
	public String [] drinks = { "acqua", "Coca Cola", "Fanta", "Sprite", "the freddo" };

	private Semaphore machine = new Semaphore(1);

	public void select() {
		try {
			Thread current = Thread.currentThread();
			String name = current.getName();

			// attende tra zero e 10 secondi per entrare nell'area di ristoro
			int pause = ThreadLocalRandom.current().nextInt(0, 11);
			current.sleep(pause*1000);

			System.out.println(name + " entra nella zona pausa.");

			machine.acquire();

			pause = ThreadLocalRandom.current().nextInt(5, 11);
			current.sleep(pause*1000);
			int pick = ThreadLocalRandom.current().nextInt(drinks.length);
			System.out.println(name + " ha selezionato " + drinks[pick] + ".");

			machine.release();
		}
		catch (InterruptedException e) {
			e.printStackTrace();
		}
	}
}

class Target implements Runnable {
	private VendingMachine dMachine;

	public Target(VendingMachine dMachine) {
		this.dMachine = dMachine;
	}

	@Override
	public void run() {
		dMachine.select();
	}
}

public class Esercizio18 {
	public static void main(String [] args) {
		VendingMachine dMachine = new VendingMachine();

		for (int i = 0; i < 10; i++) {
			Thread consumer = new Thread(new Target(dMachine));
			consumer.start();
		}
	}
}

