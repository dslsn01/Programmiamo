/* file StaticMethodCube.java */

public class StaticMethodCube {
	/* definizione del metodo cube(): è dichiarato static */ 

	static int cube(final int n) {
		int cube = n * n * n;
		return cube;
	}

	public static void main(String [] args) {
		/* dichiara tre variabili */

		int n1 = 3;
		int n2 = 4;
		int n3 = 5;
		
		/* calcola i cubi invocando il metodo statico cube() */

		int cube1 = cube(n1);
		int cube2 = cube(n2);
		int cube3 = cube(n3);

		/* stampa i cubi */

		System.out.println(n1 + " al cubo = " + cube1);
		System.out.println(n2 + " al cubo = " + cube2);
		System.out.println(n3 + " al cubo = " + cube3);
	}
}

