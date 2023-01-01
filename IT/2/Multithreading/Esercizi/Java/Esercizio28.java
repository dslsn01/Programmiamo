/* file Esercizio28.java */

import java.util.concurrent.ThreadLocalRandom;
import java.util.concurrent.Semaphore;

// la "sala d'aspetto" del barbiere contiene tutte le variabili e i semafori per coordinare il lavoro dei thread 
public class Esercizio28 {
	private Semaphore barberReady = new Semaphore(0);
	private Semaphore accessWRSeats = new Semaphore(1);
	private Semaphore customerReady = new Semaphore(0);
	private int numberOfFreeWRSeats = 5;
	private String [] customers = new String[numberOfFreeWRSeats];

	class Barber implements Runnable {
		@Override
		public void run() {
			Thread t = Thread.currentThread();
			String tb = t.getName();
			while (true) {
				try {
					customerReady.acquire();
					accessWRSeats.acquire();
					String tc = customers[numberOfFreeWRSeats];
					numberOfFreeWRSeats++;
					accessWRSeats.release();
					barberReady.release();
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
			try {
				accessWRSeats.acquire();
				if (numberOfFreeWRSeats > 0) {
					numberOfFreeWRSeats -= 1;
					customers[numberOfFreeWRSeats] = tc;
					System.out.println(tc + " si siede e aspetta di farsi tagliare i capelli...");
					accessWRSeats.release();
					customerReady.release();
					barberReady.acquire();
				}
				else {
					System.out.println("Il cliente " + tc + " non ha trovato posto per sedersi ed esce dal negozio...");
					accessWRSeats.release();
				}
			}
			catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
	}

	/* il costruttore avvia l'applicazione */

	public Esercizio28() {
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
		new Esercizio28();
	}
}

