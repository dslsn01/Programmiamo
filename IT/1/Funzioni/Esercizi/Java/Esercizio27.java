/* file Esercizio27.java */

import java.util.Arrays;
import java.util.List;
import java.util.ArrayList;

public class Esercizio27 {
	public static void pFact(int n, int f, List<Integer> fact) {
		if (n < 2) return;
		if (n % f == 0) {
			pFact(n/f, f, fact);
			fact.add(f);
		}
		else {
			pFact(n, ++f, fact);
		}
	}

	public static void main(String [] args) {
		for (int i = 4; i < 20; i++) {
			List<Integer> fact = new ArrayList<>();
			pFact(i, 2, fact);
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

