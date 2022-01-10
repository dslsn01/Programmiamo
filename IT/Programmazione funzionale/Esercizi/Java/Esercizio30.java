/* file Esercizio30.java */

import java.util.List;
import java.util.Random;
import java.util.stream.Stream;
import java.util.stream.Collectors;

public class Esercizio30 {
	private static List<Integer> merge(List<Integer> l, List<Integer> r) {
		if (l.isEmpty()) return r;
		if (r.isEmpty()) return l;

		if (l.get(0) > r.get(0)) {
			Stream<Integer> hd = r.stream().findFirst().map(Stream::of).orElseGet(Stream::of);
			List<Integer> cons = merge(l, r.subList(1, r.size()));
			return Stream.concat(hd, cons.stream()).collect(Collectors.toList());
		}
		else {
			Stream<Integer> hd = l.stream().findFirst().map(Stream::of).orElseGet(Stream::of);
			List<Integer> cons = merge(l.subList(1, l.size()), r);
			return Stream.concat(hd, cons.stream()).collect(Collectors.toList());
		}
	}

	private static List<Integer> mergesort(List<Integer> li) {
		if (li.size() <= 1) return li;
		int mid = li.size() / 2;
		List<Integer> l = mergesort(li.subList(0, mid));
		List<Integer> r = mergesort(li.subList(mid, li.size()));
		return merge(l, r);
	}

	public static void main(String [] args) {
		Random rand = new Random();
		List<Integer> li = rand.ints(25, 1, 100).boxed().collect(Collectors.toList());

		List<Integer> li2 = mergesort(li);

		System.out.println(li);
		System.out.println(li2);
	}
}

