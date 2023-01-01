/* file TestRoundingError.java */

public class TestRoundingError {
	public static void main(String [] args) {
		double x = 0.1;
		double y = 1.0;

		for (int i = 1; i < 10; i++) {
			System.out.println(x);
			x += 0.1;
		}

		if (x == y) {
			System.out.println(x + " e " + y + " sono uguali!");
		}
		else {
			System.out.println(x + " e " + y + " sono diversi!");
		}
	}
}

