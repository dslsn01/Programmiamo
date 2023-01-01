/* file Esercizio7.java */

import java.util.Arrays;

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

public class Esercizio7 {
	public static void main(String [] args) {
		int nThreads = 10;
		int [] arr = new int[nThreads];

		for (int i = 0, j = 1; i < arr.length; i++, j++) {
			arr[i] = j;
		}

		Thread [] threads = new Thread[nThreads];

		for (int i = 0; i < nThreads; i++) {
			Thread t = new Thread(new Target(i, arr));
			threads[i] = t;
		}

		for (Thread t : threads) {
			t.start();
		}

		try
		{
			for (Thread t : threads) {
				t.join();
			}
		}
		catch (InterruptedException e) {
			e.printStackTrace();
		}

		System.out.println(Arrays.toString(arr));
	}
}

