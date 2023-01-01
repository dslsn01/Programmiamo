/* file Func.java */

import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class Func {
	public static void main(String [] args) {
		List<Integer> sq = IntStream.rangeClosed(1, 10)
									.map(n -> n*n)
									.boxed()
									.collect(Collectors.toList());
		System.out.println(sq);
	}
}

