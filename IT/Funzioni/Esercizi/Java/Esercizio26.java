/* file Esercizio26.java */

import java.util.Arrays;
import java.util.List;
import java.util.ArrayList;

public class Esercizio26 {
	public static void pFact(int n, List<Integer> fact) {
		if (n <= 3) return;
		int m = n;
		double sr = Math.sqrt(n);
		for (int f = 2; f < (int)sr+1; f++) {
			while (m % f == 0) {
				fact.add(f);
				m = m / f;
			}
		}
		if (m > 1) fact.add(m);
	}

	public static void main(String [] args) {
		for (int i = 4; i < 20; i++) {
			List<Integer> fact = new ArrayList<>();
			pFact(i, fact);
			System.out.print(i);
			if (fact.size() > 1) {
				System.out.print(" = ");
				for (int j = 0; j < fact.size(); j++) {
					System.out.print(fact.get(j));
					if (j < fact.size()-1) System.out.print(" * ");
				}
				System.out.print(System.lineSeparator());
			}
			else {
				System.out.println(" primo.");
			}
		}
	}
}

