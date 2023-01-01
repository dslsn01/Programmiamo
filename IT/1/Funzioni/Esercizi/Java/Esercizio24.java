/* file Esercizio24.java */

public class Esercizio24 {
	public static int mcd(int m, int n) {
		if (n == 0) return 0;
		int r = m % n;
		if (r == 0) { return n; }
		else {
			return mcd(n, r);
		}
	}

	public static void main(String [] args) {
		System.out.printf("MCD(%d, %d) = %d\n", 24, 36, mcd(24, 36));
		System.out.printf("MCD(%d, %d) = %d\n", 42, 56, mcd(42, 56));
		System.out.printf("MCD(%d, %d) = %d\n", 54, 72, mcd(54, 72));
	}
}

