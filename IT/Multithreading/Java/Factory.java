/* file Factory.java */

import java.util.List;
import java.util.ArrayList;
import java.util.concurrent.Executors;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.Future;
import java.util.concurrent.Callable;
import java.util.concurrent.TimeUnit;

/* classe che rappresenta una componente di un elicottero */

class Part {
	private String name;

	public Part(String name) {
		setName(name);
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getName() {
		return this.name;
	}
}

class Worker implements Callable<Part> {
	private String type;

	public Worker(String type) {
		this.type = type;
	}

	/* metodo che assembla una singola parte di elicottero */
	@Override
	public Part call() throws Exception {
		return new Part(type);
	}
}

public class Factory {
	public static void main(String [] args) {
		String [] t = {"elica", "motore", "carrello di atterraggio", "telaio", "parabrezza", "cloche", "sedile"};

		final int N_WORKERS = t.length;
		ExecutorService threadPool = Executors.newFixedThreadPool(N_WORKERS);
		List<Future<Part>> parts = new ArrayList<>();

		for (int i = 0; i < N_WORKERS; i++) {
			Future<Part> p = threadPool.submit(new Worker(t[i]));
			parts.add(p);
		}

		threadPool.shutdown();
		
		try {
			threadPool.awaitTermination(1, TimeUnit.SECONDS);

			for (int i = 0; i < parts.size(); i++) {
				Future<Part> future = parts.get(i);
				Part p = future.get();
				System.out.println("Assemblato -> " + p.getName() + ".");
			}

			System.out.println("Montiamo l'elicottero pronto al decollo!");
		}
		catch (ExecutionException e) {
			System.err.println(e);
		}
		catch (InterruptedException e) {
			System.err.println(e);
		}
	}
}

