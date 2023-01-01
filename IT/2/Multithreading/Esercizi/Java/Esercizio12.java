/* file Esercizio12.java */

import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

class Target implements Runnable {
	private Lock lock;
 
	public Target(Lock lock) {
		this.lock = lock;
	}

	@Override
	public void run() {
		lock.lock();
		try
		{
			Thread t = Thread.currentThread();
			String name = t.getName();

			System.out.println("Il thread " + name + " entra nel metodo run().");
			t.sleep(5000);
			System.out.println("Il thread " + name + " esce dal metodo run().");
		}
		catch (InterruptedException e) {
			e.printStackTrace();
		}
		finally {
			lock.unlock();
		}
	}
}

public class Esercizio12 {
	public static void main(String [] args) {
		final Lock lock = new ReentrantLock();

		for (int i = 0; i < 3; i++) {
			Thread t = new Thread(new Target(lock));
			t.start();
		}
	}
}

