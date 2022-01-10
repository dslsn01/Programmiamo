/* file Esercizio11.java */

import java.util.Arrays;

class Target implements Runnable {
	private double [] v;
	private double value;
	private int pos;

	public Target(double [] v, double value, int pos) {
		this.v = v;
		this.value = value;
		this.pos = pos;
	}

	@Override
	public void run() {
		v[pos] *= value;
	}
}

public class Esercizio11 {
	public static void main(String [] args) {
		double [] v = new double[3];

		// x, y, z
		v[0] = 1.0;
		v[1] = 2.0;
		v[2] = 3.0;

		System.out.println(Arrays.toString(v));

		try {
			double scalar = 2.0;

			Thread t1 = new Thread(new Target(v, scalar, 0));
			Thread t2 = new Thread(new Target(v, scalar, 1));
			Thread t3 = new Thread(new Target(v, scalar, 2));

			t1.start();
			t2.start();
			t3.start();

			t1.join();
			t2.join();
			t3.join();

			System.out.println(Arrays.toString(v));
		}
		catch (InterruptedException e) {
			e.printStackTrace();
		}
	}
}

