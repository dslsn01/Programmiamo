/* file Multithreading1.java */

public class Multithreading1 {
	public static void main(String [] args) {
		try
		{
			// ottiene un riferimento al thread principale dell'applicazione
			Thread main = Thread.currentThread();
			String name = main.getName();
			System.out.println("Thread " + name);

			// arresta il processo principale per 5 secondi
			main.sleep(5000);

			System.out.println("Fine del thread " + Thread.currentThread().getName() + ".");
		}
		catch (InterruptedException e) {
			System.err.println(e);
		}
	}
}

