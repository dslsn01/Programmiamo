/* file Esercizio19.java */

import java.util.concurrent.ThreadLocalRandom;
import java.util.concurrent.Semaphore;

class PollingStation {
	private Semaphore cabin = new Semaphore(4);

	public void vote() {
		try {
			Thread current = Thread.currentThread();
			String name = current.getName();

			// attende tra zero e 10 secondi per entrare nel seggio elettorale
			int pause = ThreadLocalRandom.current().nextInt(0, 11);
			current.sleep(pause*1000);

			System.out.println(name + " entra nel seggio elettorale.");

			cabin.acquire();
			pause = ThreadLocalRandom.current().nextInt(5, 10+1);
			current.sleep(pause*1000);
			System.out.println(name + " ha votato.");
			cabin.release();
		}
		catch (InterruptedException e) {
			e.printStackTrace();
		}
	}
}

class Target implements Runnable {
	private PollingStation pStation;

	public Target(PollingStation pStation) {
		this.pStation = pStation;
	}

	@Override
	public void run() {
		pStation.vote();
	}
}

public class Esercizio19 {
	public static void main(String [] args) {
		PollingStation pStation = new PollingStation();

		for (int i = 0; i < 25; i++) {
			Thread voter = new Thread(new Target(pStation));
			voter.start();
		}
	}
}

