/* file CopyShop.java */

import java.util.concurrent.ThreadLocalRandom;
import java.util.concurrent.Semaphore;

public class CopyShop {
	private static class PrintingJob implements Runnable {
		private String document;
		private Semaphore printer;

		public PrintingJob(String document, Semaphore printer) {
			this.document = document;
			this.printer = printer;
		}

		@Override
		public void run() {
			try {
				// documento inviato in un intervallo di tempo tra 1 e 25 secondi
				int pause = ThreadLocalRandom.current().nextInt(1, 25+1);
				Thread current = Thread.currentThread();
				current.sleep(pause*1000);

				System.out.println(current.getName() + " invia il documento \"" + document + "\" alla stampante.");

				// acquisisce il semaforo-stampante
				printer.acquire();

				pause = ThreadLocalRandom.current().nextInt(5, 10+1);
				current.sleep(pause*1000);
				System.out.println("Stampato il documento \"" + document + "\" inviato dal " + current.getName() + ".");

				// libera il semaforo-stampante
				printer.release();
			}
			catch (InterruptedException e) {
				System.err.println(e);
			}
		}
	}

	public static void main(String [] args) {
		// il semaforo rappresenta una stampante condivisa
		Semaphore printer = new Semaphore(1);

		String [] documents = { "Modulo di iscrizione", "Appunti d'esame", "Tesi laurea triennale", "Tesi laurea specialistica", "Tesi dottorato" };

		for (int i = 0; i < 10; i++) {
			int t = ThreadLocalRandom.current().nextInt(documents.length);
			Thread student = new Thread(new PrintingJob(documents[t], printer));
			student.start();
		}
	}
}

