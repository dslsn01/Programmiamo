/* file Esercizio12.java */

public class Esercizio12 {
	private static int isum(int n) {
		int tot = 0;
		for (int i = 1; i <= n; i++) {
			tot += i;
		}

		return tot;
	}

	public static void main(String [] args) {
		System.out.println("Somma dei numeri da 1 a 100 = " + isum(100));
	}
}

