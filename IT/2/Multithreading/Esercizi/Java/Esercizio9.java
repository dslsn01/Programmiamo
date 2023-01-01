/* file Esercizio9.java */

import java.util.Arrays;
import java.util.List;
import java.util.ArrayList;
import java.util.concurrent.Executors;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.Future;
import java.util.concurrent.Callable;
import java.util.concurrent.TimeUnit;

class Target implements Callable<int[]> {
	private int index;

	public Target(int index) {
		this.index = index;
	}

	@Override
	public int [] call() throws Exception {
		int [] row = new int[10];

		for (int i = 0; i < 10; i++) {
			row[i] = index;
		}

		for (int index = 0, k = 1; index < 10; index++, k++) {
			row[index] *= k;
		}

		return row;
	}
}

public class Esercizio9 {
	public static void main(String [] args) {
		int nThreads = 10;

		ExecutorService threadPool = Executors.newFixedThreadPool(nThreads);
		List<Future<int[]>> tbp = new ArrayList<>();

		for (int i = 1; i <= nThreads; i++) {
			Future<int[]> row = threadPool.submit(new Target(i));
			tbp.add(row);
		}

		threadPool.shutdown();
		try {
			threadPool.awaitTermination(1, TimeUnit.SECONDS);
		}
		catch (InterruptedException e) {
			e.printStackTrace();
		}

		try {
			for (Future<int[]> row : tbp) {
				System.out.println(Arrays.toString(row.get()));
			}
		}
		catch (ExecutionException e) {
			e.printStackTrace();
		}
		catch (InterruptedException e) {
			e.printStackTrace();
		} 
	}
}

