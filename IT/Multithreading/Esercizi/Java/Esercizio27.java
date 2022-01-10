/* file Esercizio27.java */

import java.util.concurrent.Semaphore;
 
public class Esercizio27 {
	private int readCount = 0;
	private Semaphore resourceAccess = new Semaphore(1);
	private Semaphore readCountAccess = new Semaphore(1);
	private Semaphore serviceQueue = new Semaphore(1);

	// thread scrittore
	class Writer implements Runnable {
		@Override
		public void run() {
			try {
				serviceQueue.acquire();
				resourceAccess.acquire();
				serviceQueue.release();

				System.out.println(Thread.currentThread().getName() + " scrive.");

				resourceAccess.release();
			}
			catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
	}

	// thread lettore
	class Reader implements Runnable {
		@Override
		public void run() {
			try {
				serviceQueue.acquire();
				readCountAccess.acquire();

				if (readCount == 0) {
					resourceAccess.acquire();
				}

				readCount++;

				serviceQueue.release();
				readCountAccess.release();

				System.out.println(Thread.currentThread().getName() + " legge.");

				readCountAccess.acquire();
				readCount--;

				if (readCount == 0) {
					resourceAccess.release();
				}

				readCountAccess.release();
			}
			catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
	}

	/* il costruttore avvia l'applicazione */

	public Esercizio27() {
		final int N_WRITERS = 5;
		final int N_READERS = 10;

		for (int i = 0; i < N_WRITERS; i++) {
			Thread writer = new Thread(new Writer());
			writer.start();
		}

		for (int i = 0; i < N_READERS; i++) {
			Thread reader = new Thread(new Reader());
			reader.start();
		}
	}

	public static void main(String [] args) {
		new Esercizio27();
	}
}

