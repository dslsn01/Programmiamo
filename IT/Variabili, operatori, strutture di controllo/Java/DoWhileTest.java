/* file DoWhileTest.java */

public class DoWhileTest {
	public static void main(String [] args) {
		/* inizializza la variabile contatore */

		int c = 5;

		/* esegue una prima volta le istruzioni nel ciclo, quindi itera finché la variabile contatore è minore di 5 */

		do {
			System.out.println(c);
		}
		while (c < 5);

		System.out.println("Fine del ciclo.");
	}
}

