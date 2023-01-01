/* file Esercizio15.java */

import java.util.concurrent.atomic.AtomicInteger;

class TargetAdd implements Runnable {
	private Object monitor;
	private AtomicInteger value;
 
	public TargetAdd(Object monitor, AtomicInteger value) {
		this.monitor = monitor;
		this.value = value;
	}

	@Override
	public void run() {
		synchronized(monitor) {
			String name = Thread.currentThread().getName();
			while (value.get() > 0) {
				try {
					monitor.wait();
				}
				catch (InterruptedException e) {
					e.printStackTrace();
				}
			}

			System.out.println(name + " - variabile (prima dell'incremento): " + value);
			int newValue = value.incrementAndGet();
			System.out.println(name + " - variabile (dopo l'incremento): " + newValue);
			monitor.notify();
		}
	}
}

class TargetSubtr implements Runnable {
	private Object monitor;
	private AtomicInteger value;
 
	public TargetSubtr(Object monitor, AtomicInteger value) {
		this.monitor = monitor;
		this.value = value;
	}

	@Override
	public void run() {
		synchronized(monitor) {
			String name = Thread.currentThread().getName();
			while (value.get() == 0) {
				try {
					monitor.wait();
				}
				catch (InterruptedException e) {
					e.printStackTrace();
				}
			}

			System.out.println(name + " - variabile (prima del decremento): " + value);
			int newValue = value.decrementAndGet();
			System.out.println(name + " - variabile (dopo il decremento): " + newValue);
			monitor.notify();
		}
	}
}

public class Esercizio15 {
	public static void main(String [] args) {
		final Object monitor = new Object();
		AtomicInteger value = new AtomicInteger(0);

		Thread t1 = new Thread(new TargetAdd(monitor, value));
		Thread t2 = new Thread(new TargetSubtr(monitor, value));

		t1.start();
		t2.start();
	}
}

