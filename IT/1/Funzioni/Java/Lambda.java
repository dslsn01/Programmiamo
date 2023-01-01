/* file Lambda.java */

import java.util.function.IntUnaryOperator;

public class Lambda {
	public static void main(String [] args) {
		// dichiara una funzione lambda (anonima)
		IntUnaryOperator f = (n) -> n * n;

		int n = 3;
		int square = f.applyAsInt(n);

		System.out.println(n + " al quadrato = " + square);
	}
}

