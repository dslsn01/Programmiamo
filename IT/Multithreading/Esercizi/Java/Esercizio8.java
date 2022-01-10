/* file Esercizio8.java */

import java.util.Arrays;
import java.util.concurrent.Executors;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.TimeUnit;

class Target implements Runnable {
	int index;
	int [] arr;

	public Target(int index, int [] arr) {
		this.index = index;
		this.arr = arr;
	}

	@Override
	public void run() {
		arr[index] *= arr[index];
	}
}

public class Esercizio8 {
	public static void main(String [] args) {
		int nThreads = 10;
		int [] arr = new int[nThreads];

		for (int i = 0, j = 1; i < arr.length; i++, j++) {
			arr[i] = j;
		}

		ExecutorService threadPool = Executors.newFixedThreadPool(nThreads);

		Thread [] threads = new Thread[nThreads];

		for (int i = 0; i < nThreads; i++) {
			threadPool.submit(new Target(i, arr));
		}

		threadPool.shutdown();
		try {
			threadPool.awaitTermination(1, TimeUnit.SECONDS);
		}
		catch (InterruptedException e) {
			e.printStackTrace();
		}

		System.out.println(Arrays.toString(arr));
	}
}

