/* file Esercizio15.java */

import java.util.concurrent.atomic.AtomicInteger;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

class Target implements Runnable {
	private Lock lock;
	private AtomicInteger value;
 
	public Target(Lock lock, AtomicInteger value) {
		this.lock = lock;
		this.value = value;
	}

	@Override
	public void run() {
		lock.lock();
		try {
			for (int i = 0; i < 3; i++) {
				int newValue = value.incrementAndGet();
				System.out.print(value + " ");
				Thread.currentThread().sleep(1000);
			}
		}
		catch (InterruptedException e) {
			e.printStackTrace();
		}
		finally {
			lock.unlock();
		}
	}
}

public class Esercizio16 {
	public static void main(String [] args) {
		final Lock lock = new ReentrantLock();
		AtomicInteger v = new AtomicInteger(0);

		Thread [] threads = new Thread[3];

		for (int i = 0; i < 3; i++) {
			threads[i] = new Thread(new Target(lock, v));
		}

		for (Thread t : threads) {
			t.start();
		}

		try {
			for (Thread t : threads) {
				t.join();
			}
		}
		catch (InterruptedException e) {
			e.printStackTrace();
		}

		System.out.print(System.lineSeparator());
	}
}

