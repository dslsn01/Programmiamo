/* file Hof.java */

import java.util.Comparator;
import java.util.List;
import java.util.Random;
import java.util.stream.Collectors;

public class Hof {
	public static void main(String [] args) {
		Random rand = new Random();
		List<Integer> nums = rand.ints(20, 1, 100)
								 .boxed()
								 .collect(Collectors.toList());

		Comparator<Integer> cmp = (m, n) -> {
			boolean m_e = (m % 2 == 0);
			boolean n_e = (n % 2 == 0);
			// se m e n sono entrambi pari o entrambi dispari
			if (m_e && n_e || !m_e && !n_e) return m.compareTo(n);
			return (m_e && !n_e) ? 1 : -1;
		};

		System.out.println(cmp);

		List<Integer> s = nums.stream()
							  .sorted(cmp)
							  .collect(Collectors.toList());

		System.out.println("Lista originale:");
		System.out.println(nums);
		System.out.println("Numeri pari a destra, dispari a sinistra:");
		System.out.println(s);
	}
}

