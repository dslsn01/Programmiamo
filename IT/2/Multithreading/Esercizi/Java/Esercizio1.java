/* file Esercizio1.java */

class ChildThread extends Thread {
	@Override
	public void run() {
		try {
			String threadName = getName();
			System.out.println("Inizio del thread " + threadName + ".");
			sleep(5000);
			System.out.println("Fine del thread " + threadName + ".");
		}
		catch (InterruptedException e) {
			e.printStackTrace();
		}
	}
}

public class Esercizio1 {
	public static void main(String [] args) {
		try
		{
			String main = Thread.currentThread().getName();
			System.out.println("Thread " + main);

			Thread t = new ChildThread();
			t.start();
			t.join();

			System.out.println("Fine del thread " + main + ".");
		}
		catch (InterruptedException e) {
			e.printStackTrace();
		}
	}
}

