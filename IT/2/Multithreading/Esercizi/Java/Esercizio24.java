/* file Esercizio24.java */

import java.util.concurrent.ThreadLocalRandom;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

class Philosopher implements Runnable {
	private Lock [] forks;
	private int rIndex;
	private int lIndex;

	public Philosopher(Lock [] forks, int rIndex, int lIndex) {
		this.forks = forks;
		this.rIndex = rIndex;
		this.lIndex = lIndex;
	}

	@Override
	public void run() {
		Thread t = Thread.currentThread();
		while (true) {
			try {
				if (forks[rIndex].tryLock(10, TimeUnit.MILLISECONDS)) {
					if (forks[lIndex].tryLock(10, TimeUnit.MILLISECONDS)) {
						System.out.println(t.getName() + " prende le forchette " + rIndex + " e " + lIndex + ".");
						System.out.println(t.getName() + " sta mangiando.");

						// ogni filosofo impiega tra 4 e 8 secondi per mangiare
						int pause = ThreadLocalRandom.current().nextInt(4, 8+1);
						t.sleep(pause*1000);

						System.out.println(t.getName() + " posa le forchette " + rIndex + " e " + lIndex + ".");

						forks[lIndex].unlock();
					}

					forks[rIndex].unlock();
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

public class Esercizio24 {
	public static void main(String [] args) {
		final int N_PHILOSOPHERS = 5;
		String [] names = {"Platone", "Pitagora", "Kant", "Leibniz", "Marx"};
		Lock [] forks = new Lock[N_PHILOSOPHERS];

		for (int i = 0; i < N_PHILOSOPHERS; i++) {
			forks[i] = new ReentrantLock();
		}

		for (int i = 0; i < N_PHILOSOPHERS; i++) {
			Thread philosopher = new Thread(new Philosopher(forks, i, (i+1) % N_PHILOSOPHERS), names[i]);
			philosopher.start();
		}
	}
}

