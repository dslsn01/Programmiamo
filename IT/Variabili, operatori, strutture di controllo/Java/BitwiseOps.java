/* file BitwiseOps.java */

public class BitwiseOps {
	public static void main(String [] args) {
		// insieme A: numeri pari
		int a = 0;

		// insieme B: numeri dispari
		int b = 0;

		// insieme C: multipli di 3, pari e dispari
		int c = 0;

		for (int i = 2; i < 32; i++) {
			if ((i & 1) == 0) {
				a |= (1 << i);
			}
		}

		for (int i = 0; i < 32; i++) {
			if ((i & 1) == 1) {
				b |= (1 << i);
			}
		}

		for (int i = 3; i < 32; i += 3) {
			c |= (1 << i);
		}

		// stampa gli elementi di A

		String s_a = String.format("%32s", Integer.toBinaryString(a)).replace(" ", "0");
		System.out.println("A = {" + s_a + "}");

		for (int i = 2; i < 32; i++) {
			if ((a & (1 << i)) != 0) {
				System.out.print(i + " ");
			}
		}

		System.out.print(System.lineSeparator());

		// stampa gli elementi di B

		System.out.println("B = {" + Integer.toBinaryString(b) + "}");

		for (int i = 1; i < 32; i++) {
			if ((b & (1 << i)) != 0) {
				System.out.print(i + " ");
			}
		}

		System.out.print(System.lineSeparator());

		String s_c = String.format("%32s", Integer.toBinaryString(c)).replace(" ", "0");
		System.out.println("C = {" + s_c + "}");

		for (int i = 0; i < 32; i++) {
			if ((c & (1 << i)) != 0) {
				System.out.print(i + " ");
			}
		}

		System.out.print(System.lineSeparator());

		// unione insiemistica A u B

		int aub = a | b;

		System.out.println("A u B = {" + Integer.toBinaryString(aub) + "}");

		for (int i = 0; i < 32; i++) {
			if ((aub & (1 << i)) != 0) {
				System.out.print(i + " ");
			}
		}

		System.out.print(System.lineSeparator());

		// intersezione insiemistica: B & C (multipli di tre che sono dispari)

		int bec = b & c;

		String s_bec = String.format("%32s", Integer.toBinaryString(bec)).replace(" ", "0");
		System.out.println("B & C = {" + s_bec + "}");

		for (int i = 0; i < 32; i++) {
			if ((bec & (1 << i)) != 0) {
				System.out.print(i + " ");
			}
		}

		System.out.print(System.lineSeparator());

		// complemento (A u B) \ C (pari e dispari meno i multipli di tre)

		int aub_c = aub & ~c;

		System.out.println("(A u B) \\ C = {" + Integer.toBinaryString(aub_c) + "}");

		for (int i = 0; i < 32; i++) {
			if ((aub_c & (1 << i)) != 0) {
				System.out.print(i + " ");
			}
		}

		System.out.print(System.lineSeparator());

		// differenza simmetrica B ^ C: numeri dispari oppure pari multipli di tre

		int b_c = b ^ c;

		System.out.println("B ^ C = {" + Integer.toBinaryString(b_c) + "}");

		for (int i = 0; i < 32; i++) {
			if ((b_c & (1 << i)) != 0) {
				System.out.print(i + " ");
			}
		}

		System.out.print(System.lineSeparator());
	}
}

