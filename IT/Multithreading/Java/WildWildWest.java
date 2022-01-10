/* file WildWildWest.java */

import java.util.concurrent.ThreadLocalRandom;

class CowShd {
	public synchronized void tieCows() {
		try {
			for (int i = 0; i < 3; i++) {
				/* ottiene un riferimento al thread il cowboy che esegue il blocco di codice */
				String cowboy = Thread.currentThread().getName();
				System.out.println("Il cowboy " + cowboy + " sta chiudendo le sue mucche nella stalla...");

				int pause = ThreadLocalRandom.current().nextInt(1, 3+1);
				Thread.sleep(pause * 1000);
			}
		} catch (InterruptedException e) {
			System.err.println(e);
		}
	}
}

class CowBoy implements Runnable { 
	private CowShd cs;

	public CowBoy(CowShd cs) {
		this.cs = cs;
	}

	@Override
	public void run() {
		this.cs.tieCows();
	}
}

public class WildWildWest {
	public static void main(String [] args) {
		/* crea una nuova stalla */

		CowShd cs = new CowShd();

		/* i due oggetti CowBoy condividono la stessa stalla */

		CowBoy a = new CowBoy(cs);
		CowBoy b = new CowBoy(cs);

		/* istanzia due thread che eseguono il metodo run() di un oggetto CowBoy */

		Thread t1 = new Thread(a, "Wyatt Earp");
		Thread t2 = new Thread(b, "Buffalo Bill");

		t1.start();
		t2.start();
	}
}

