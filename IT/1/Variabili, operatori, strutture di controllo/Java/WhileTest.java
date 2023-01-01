/* file WhileTest.java */

public class WhileTest {
	public static void main(String [] args) {
		/* inizializza la variabile contatore */

		int c = 0;

		/* itera per cinque volte */

		while (c < 5) {
			System.out.print(c + " ");
			c++;
		}

		/* fine del ciclo */

		System.out.print(System.lineSeparator());
		System.out.println("Fine del ciclo.");
	}
}

