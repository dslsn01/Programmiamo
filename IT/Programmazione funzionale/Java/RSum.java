/* file RSum.java */

public class RSum {
	private static int rsum(int n) {
		if (n == 0 || n == 1) return n;
		else {
			return n + rsum(n - 1);
		}
	}

	public static void main(String [] args) {
		System.out.println("Somma dei numeri da 1 a 100 = " + rsum(100));
	}
}

