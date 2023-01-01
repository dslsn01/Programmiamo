/* file Esercizio25.java */

public class Esercizio25 {
	public static int mcd(int m, int n) {
		if (n == 0) return 0;
		int r = m % n;
		if (r == 0) { return n; }
		else {
			return mcd(n, r);
		}
	}

	public static int mcm(int m, int n) {
		return (m * n) / mcd(m, n);
	}

	public static void main(String [] args) {
		System.out.printf("mcm(%d, %d) = %d\n", 640, 480, mcm(640, 480));
		System.out.printf("mcm(%d, %d) = %d\n", 1024, 768, mcd(1024, 768));
		System.out.printf("mcm(%d, %d) = %d\n", 4096, 2048, mcd(4096, 2048));
	}
}

