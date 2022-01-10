/* file Esercizio26.java */

import java.util.Deque;
import java.util.LinkedList;
import java.util.concurrent.ThreadLocalRandom;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;
import java.util.concurrent.Semaphore;
 
public class Esercizio26 {
	private final int BUFFER_SIZE = 25;
	private Lock lock = new ReentrantLock();
	private Semaphore full = new Semaphore(0);
	private Semaphore empty = new Semaphore(BUFFER_SIZE);
	private Deque<String> buffer = new LinkedList<>();

	// thread produttore
	class Producer implements Runnable {
		@Override
		public void run() {
			Thread t = Thread.currentThread();
			while (true) {
				try {
					String item = "pacco regalo";
					empty.acquire();
					lock.lock();
					// aggiunge un nuovo pacco regalo sullo scaffale
					buffer.addFirst(item);
					lock.unlock();
					System.out.println(t.getName() + " prepara un pacco regalo (" + buffer.size() + " disponibili).");
					full.release();

					int pause = ThreadLocalRandom.current().nextInt(1, 25+1);
					t.sleep(pause*1000);
				}
				catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
		}
	}

	// thread consumatore
	class Consumer implements Runnable {
		@Override
		public void run() {
			Thread t = Thread.currentThread(); 
			while (true) {
				try {
					full.acquire();

					// preleva un pacco regalo dallo scaffale
					lock.lock();
					String item = buffer.removeFirst();
					lock.unlock();

					System.out.println(t.getName() + " acquista un " + item + " (" + buffer.size() + " disponibili).");
					empty.release();

					int pause = ThreadLocalRandom.current().nextInt(1, 25+1);
					t.sleep(pause*1000);
				}
				catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
		}
	}

	/* il costruttore avvia l'applicazione */

	public Esercizio26() {
		new Thread(new Producer()).start();
		new Thread(new Consumer()).start();
	}

	public static void main(String [] args) {
		new Esercizio26();
	}
}

