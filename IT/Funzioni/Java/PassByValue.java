/* file PassByValue.java */

public class PassByValue {
	static int square(int n) {
		n = n * n;
		return n;
	}

	public static void main(String [] args) {
		int n = 2;
		System.out.println("Valore di n (prima): " + n);

		// reimposta la variabile originale

		n = square(n);
		System.out.println("Valore di n (dopo): " + n);
	}
}

