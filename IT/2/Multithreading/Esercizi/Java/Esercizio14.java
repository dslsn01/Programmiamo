/* file Esercizio14.java */

import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;
import java.util.concurrent.atomic.AtomicInteger;

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
		String name = Thread.currentThread().getName();
		try
		{
			System.out.println(name + " - variabile (prima dell'incremento): " + value);
			int newValue = value.incrementAndGet();
			System.out.println(name + " - variabile (dopo l'incremento): " + newValue);
		}
		finally {
			lock.unlock();
		}
	}
}

public class Esercizio14 {
	public static void main(String [] args) {
		final ReentrantLock lock = new ReentrantLock();
		AtomicInteger value = new AtomicInteger(0);

		Thread t1 = new Thread(new Target(lock, value));
		Thread t2 = new Thread(new Target(lock, value));

		t1.start();
		t2.start();
	}
}

