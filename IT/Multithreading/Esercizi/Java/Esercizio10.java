/* file Esercizio10.java */

import java.util.Arrays;

class Target implements Runnable {
	private int [] arr;
	private int start;
	private int end;

	public Target(int [] arr, int start, int end) {
		this.arr = arr;
		this.start = start;
		this.end = end;
	}

	@Override
	public void run() {
		for (int i = start; i < end; i++) {
			arr[i] = i + 1;
		}
	}
}

public class Esercizio10 {
	public static void main(String [] args) {
		int [] arr = new int[9];
		System.out.println(Arrays.toString(arr));

		try {
			Thread t1 = new Thread(new Target(arr, 0, 3));
			Thread t2 = new Thread(new Target(arr, 3, 6));
			Thread t3 = new Thread(new Target(arr, 6, 9));

			t1.start();
			t2.start();
			t3.start();

			t1.join();
			t2.join();
			t3.join();

			System.out.println(Arrays.toString(arr));
		}
		catch (InterruptedException e) {
			e.printStackTrace();
		}
	}
}

