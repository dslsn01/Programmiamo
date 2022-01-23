/* file TestBigDecimal.java */

import java.math.BigDecimal;

public class TestBigDecimal {
	public static void main(String [] args) {
		BigDecimal x = new BigDecimal("0.1");
		BigDecimal y = new BigDecimal("1.0");

		for (int i = 1; i < 10; i++) {
			System.out.println(x);
			x = x.add(new BigDecimal("0.1"));
		}

		if (x.equals(y)) {
			System.out.println(x + " e " + y + " sono uguali!");
		}
		else {
			System.out.println(x + " e " + y + " sono diversi!");
		}
	}
}

