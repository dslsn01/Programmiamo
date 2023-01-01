/* file Esercizio17.java */

import java.util.concurrent.ThreadLocalRandom;
import java.util.concurrent.Semaphore;

class Car implements Runnable {
	private Semaphore semaphore;

	public Car(Semaphore semaphore) {
		this.semaphore = semaphore;
	}

	@Override
	public void run() {
		try {
			Thread auto = Thread.currentThread();

			// andatura dell'auto compresa tra 45 e 90 km orari 
			int speed = ThreadLocalRandom.current().nextInt(45, 90+1);
			System.out.println("L'auto " + auto.getName() + " viaggia a " + speed + " km/h...");
			int pause = ThreadLocalRandom.current().nextInt(3, 6);
			auto.sleep(pause*1000);

			semaphore.acquire();

			System.out.println(auto.getName() + " attraversa l'incrocio.");
		}
		catch (InterruptedException e) {
			e.printStackTrace();
		}
		finally {
			semaphore.release();
		}
	}
}

public class Esercizio17 {
	public static void main(String [] args) {
		Semaphore semaphore = new Semaphore(3);

		for (int i = 0; i < 25; i++) {
			try {
				Thread car = new Thread(new Car(semaphore));
				car.start();
				int pause = ThreadLocalRandom.current().nextInt(0, 2);
				Thread.currentThread().sleep(pause*1000);
			}
			catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
	}
}

