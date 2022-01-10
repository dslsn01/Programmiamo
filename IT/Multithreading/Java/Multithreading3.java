/* file Multithreading3.java */

import java.util.concurrent.ThreadLocalRandom;

/* le classi MainFunc e SelectFromDb implementano l'interfaccia Runnable, e definiscono il metodo run() */

class SelectFromDb implements Runnable {
	@Override
	public void run() {
		Thread t = Thread.currentThread();
		String tName = t.getName();
		System.out.println(tName + " - selezione database");

		try {
			for (int i = 0; i < 3; i++) {
				System.out.println(tName + " - elaborazione dati...");
				// pausa da 1 a 3 secondi
				int pause = ThreadLocalRandom.current().nextInt(1, 3+1);
				t.sleep(pause * 1000);
			}
		} catch (InterruptedException e) {
			System.err.println(e);
		}
	}
}

class MainFunc implements Runnable {
	@Override
	public void run() {
		Thread t = Thread.currentThread();
		String tName = t.getName();

		try {
			for (int i = 0; i < 3; i++) {
				System.out.println(tName + " - ciclo principale");
				// pausa da 1 a 3 secondi
				int pause = ThreadLocalRandom.current().nextInt(1, 3+1);
				t.sleep(pause * 1000);
			}
		} catch (InterruptedException e) {
			System.err.println(e);
		}
	}
}

public class Multithreading3 {
	public static void main(String [] args) {
		try {
			/* crea due nuovi thread di tipo Runnable */

			MainFunc process = new MainFunc();
			Thread t1 = new Thread(process, "MAIN");

			SelectFromDb select = new SelectFromDb();
			Thread t2 = new Thread(select, "BACKGROUND");

			/* abilita i nuovi thread */

			t1.start();
			t2.start();

			t1.join();
			t2.join();

			System.out.println("Dati dal database pronti all'uso!");
		}
		catch (InterruptedException e) {
			System.err.println(e);
		}
	}
}

