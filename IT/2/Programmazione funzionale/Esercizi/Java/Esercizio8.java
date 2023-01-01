/* file Esercizio8.java */

import java.util.List;
import java.util.stream.IntStream;
import java.util.stream.Collectors;
import java.util.function.Function;

public class Esercizio8 {
	private static List<Integer> npow(int n, List<Integer> li) {
		Function<Integer, Function<Integer, Integer>> f = k -> p -> (int) Math.pow(k, p);
		Function<Integer, Integer> by2 = f.apply(n);
		return li.stream().map(Function.identity()).map(by2::apply).collect(Collectors.toList());
	}

	public static void main(String [] args) {
		List<Integer> li = IntStream.rangeClosed(1, 10).boxed().collect(Collectors.toList());
		System.out.println(li);

		List<Integer> p = npow(2, li);
		System.out.println(p);
	}
}

