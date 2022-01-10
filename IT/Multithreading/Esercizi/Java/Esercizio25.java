/* file Esercizio25.java */

import java.util.concurrent.ThreadLocalRandom;
import java.util.concurrent.Semaphore;

class Philosopher implements Runnable {
	private Semaphore [] forks;
	private int rIndex;
	private int lIndex;

	public Philosopher(Semaphore [] forks, int rIndex, int lIndex) {
		this.forks = forks;
		this.rIndex = rIndex;
		this.lIndex = lIndex;
	}

	@Override
	public void run() {
		Thread t = Thread.currentThread();
		while (true) {
			try {
				if (forks[rIndex].tryAcquire()) {
					if (forks[lIndex].tryAcquire()) {
						System.out.println(t.getName() + " prende le forchette " + rIndex + " e " + lIndex + ".");
						System.out.println(t.getName() + " sta mangiando.");

						// ogni filosofo impiega tra 4 e 8 secondi per mangiare
						int pause = ThreadLocalRandom.current().nextInt(4, 8+1);
						t.sleep(pause*1000);

						System.out.println(t.getName() + " posa le forchette " + rIndex + " e " + lIndex + ".");

						forks[lIndex].release();
					}

					forks[rIndex].release();
				}

				// ogni filosofo pensa per 3/5 minuti
				int pause = ThreadLocalRandom.current().nextInt(3, 5+1);
				t.sleep(pause*1000);
				System.out.println(t.getName() + " sta pensando...");
			}
			catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
	}
}

public class Esercizio25 {
	public static void main(String [] args) {
		final int N_PHILOSOPHERS = 5;
		String [] names = {"Platone", "Pitagora", "Kant", "Leibniz", "Marx"};
		Semaphore [] forks = new Semaphore[N_PHILOSOPHERS];

		for (int i = 0; i < N_PHILOSOPHERS; i++) {
			forks[i] = new Semaphore(1);
		}

		for (int i = 0; i < N_PHILOSOPHERS; i++) {
			Thread philosopher = new Thread(new Philosopher(forks, i, (i+1) % N_PHILOSOPHERS), names[i]);
			philosopher.start();
		}
	}
}

