/* file Esercizio11.java */

import java.util.List;
import java.util.stream.IntStream;
import java.util.stream.Collectors;

public class Esercizio11 {
	private static boolean psq(int n) {
		int m = Math.round((int)Math.sqrt(n));
		return (m*m) == n ? true : false;
	}

	public static void main(String [] args) {
		List<Integer> ps = IntStream.rangeClosed(1, 100).filter(n -> psq(n)).boxed().collect(Collectors.toList());
		System.out.println(ps);
	}
}

