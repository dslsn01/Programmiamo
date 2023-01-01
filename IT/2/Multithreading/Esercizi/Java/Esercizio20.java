/* file Esercizio20.java */

import java.util.concurrent.ThreadLocalRandom;
import java.util.concurrent.Semaphore;

class Barrier {
	private int n;
	private int count;
	private Semaphore mutex;
	private Semaphore barrier;

	public Barrier(int n) {
		this.n = n;
		this.count = 0;
		this.mutex = new Semaphore(1);
		this.barrier = new Semaphore(0);
	}

	public void await() {
		try {
			mutex.acquire();
			count++;
			mutex.release();

			if (this.count == this.n) {
				barrier.release();
			}

			barrier.acquire();
			barrier.release();
		}
		catch (InterruptedException e) {
			e.printStackTrace();
		}
	}
}

class Target implements Runnable {
	private Barrier barrier;

	public Target(Barrier barrier) {
		this.barrier = barrier;
	}

	@Override
	public void run() {
		try {
			int pause = ThreadLocalRandom.current().nextInt(3, 8+1);
			Thread t = Thread.currentThread();
			t.sleep(pause * 1000);
			// System.out.println(System.currentTimeMillis() + " " + t.getName() + " arriva alla barriera.");
			barrier.await();

			// stampa l'istante in millisecondi

			System.out.println(System.currentTimeMillis() + " " + t.getName());
		}
		catch (InterruptedException e) {
			e.printStackTrace();
		}
	}
}

public class Esercizio20 {
	public static void main(String [] args) {
		final int N_THREADS = 3;
		Barrier barrier = new Barrier(N_THREADS);

		Thread [] threads = new Thread[N_THREADS];

		for (int i = 0; i < N_THREADS; i++) {
			threads[i] = new Thread(new Target(barrier));
		}

		for (Thread t : threads) {
			t.start();
		}
	}
}

