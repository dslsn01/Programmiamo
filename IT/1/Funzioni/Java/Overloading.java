/* file Overloading.java */

public class Overloading {
	static void f(int a) {
		System.out.println("f(" + a + ");");
	}

	static void f(int a, int b) {
		System.out.println("f(" + a + ", " + b + ");");
	}

	static void f(double a, double b) {
		System.out.println("f(" + a + ", " + b + ");");
	}

	public static void main(String [] args) {
		f(1);
		f(1, 2);
		f(3.14, 2.71);
	}
}

