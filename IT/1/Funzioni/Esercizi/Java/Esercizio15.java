/* file Esercizio15.java */

public class Esercizio15 {
	static double exp(double b, double ex) {
		return Math.pow(b, ex);
	}

	public static void main(String [] args) {
		System.out.println("Calcolo delle potenze.");

		double b = 1;
		double ex = 2;

		while (ex <= 10) {
			double p = exp(b, ex);
			System.out.println("Potenza di " + b + " elevato a " + ex + " = " + p);
			b++;
			ex++;
		}
	}
}

