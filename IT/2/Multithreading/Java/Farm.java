/* file Farm.java */

import java.util.concurrent.ThreadLocalRandom;

/* classe che rappresenta il fienile */

class Barn {
	private volatile int bales = 0;

	public synchronized void heap() {
		for (int i = 0; i < 3; i++) {
			try {
				while (bales > 0) {
					wait();
				}

				Thread t = Thread.currentThread();
				// pausa da 2 a 4 secondi
				int pause = ThreadLocalRandom.current().nextInt(2, 4+1);
				t.sleep(pause*1000);

				bales++;
				System.out.println(t.getName() + ": ci sono " + bales + " balle di fieno.");
				notify();
			}
			catch (InterruptedException e) {
				System.err.println(e);
			}
		}
	}

	public synchronized void eat() {
		for (int i = 0; i < 3; i++) {
			try {
				while (bales == 0) {
					wait();
				}

				Thread t = Thread.currentThread();
				// pausa da 1 a 3 secondi
				int pause = ThreadLocalRandom.current().nextInt(1, 3+1);
				t.sleep(pause*1000);

				bales--;
				System.out.println(t.getName() + ": ci sono " + bales + " balle di fieno.");
				notify();
			}
			catch (InterruptedException e) {
				System.err.println(e);
			}
		}
	}
}

/* classe che rappresenta un contadino */

class Farmer implements Runnable {
	private Barn barn;

	public Farmer(Barn barn) {
		this.barn = barn;
	}

	@Override
	public void run() {
		barn.heap();
	}
}

/* classe che rappresenta una mucca */

class Cow implements Runnable {
	private Barn barn;
	
	public Cow(Barn barn) {
		this.barn = barn;
	}

	@Override
	public void run() {
		barn.eat();
	}
}

/* la classe fattoria contiene il metodo main() */

public class Farm {
	public static void main(String [] args) {
		Barn barn = new Barn();

		Thread farmer = new Thread(new Farmer(barn), "contadino");
		Thread cow = new Thread(new Cow(barn), "mucca");

		farmer.start();
		cow.start();
	}
}

