/* file Esercizio29.java */

import java.util.concurrent.ThreadLocalRandom;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.ArrayBlockingQueue;

// la "sala d'aspetto" del barbiere contiene tutte le variabili e i semafori per coordinare il lavoro dei thread 
public class Esercizio29 {
	private final int TOT_SEATS = 5;
	private final BlockingQueue <String>customers = new ArrayBlockingQueue<>(TOT_SEATS);

	class Barber implements Runnable {
		@Override
		public void run() {
			Thread t = Thread.currentThread();
			String tb = t.getName();
			while (true) {
				try {
					String tc = customers.take();
					System.out.println("Il barbiere " + tb + " sta tagliando i capelli al cliente " + tc + ".");
					int pause = ThreadLocalRandom.current().nextInt(10, 25+1);
					t.sleep(pause*1000);

					System.out.println(tb + " ha impiegato " + pause + " minuti per tagliare i capelli a " + tc + ". Avanti un altro!");
				}
				catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
		}
	}

	// 
	class Customer implements Runnable {
		@Override
		public void run() {
			String tc = Thread.currentThread().getName();
			System.out.println("Il cliente " + tc + " entra nel negozio.");
			if (customers.remainingCapacity() > 0) {
				customers.add(tc);
				System.out.println(tc + " si siede e aspetta di farsi tagliare i capelli...");
			}
			else {
				System.out.println("Il cliente " + tc + " non ha trovato posto per sedersi ed esce dal negozio...");
			}
		}
	}

	/* il costruttore avvia l'applicazione */

	public Esercizio29() {
		Thread barber = new Thread(new Barber());
		barber.start();

		while (true) {
			try {
				Thread customer = new Thread(new Customer());
				customer.start();
				int pause = ThreadLocalRandom.current().nextInt(5, 30+1);
				Thread.currentThread().sleep(pause*1000);
			}
			catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
	}

	public static void main(String [] args) {
		new Esercizio29();
	}
}

