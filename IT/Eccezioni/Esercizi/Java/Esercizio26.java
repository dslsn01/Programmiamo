/* file Esercizio26.java */

import java.io.Console;

class InvalidDDException extends IllegalArgumentException {
	public InvalidDDException(String message) {
		super(message);
	}
}

class InvalidMMException extends IllegalArgumentException {
	public InvalidMMException(String message) {
		super(message);
	}
}

class InvalidYYYYException extends IllegalArgumentException {
	public InvalidYYYYException(String message) {
		super(message);
	}
}

class MyDate {
	private int yyyy;
	private int mm;
	private int dd;

	public MyDate(int dd, int mm, int yyyy) {
		try {
			this.setYYYY(yyyy);
		}
		catch (InvalidYYYYException e) {
			System.out.println(e.getMessage());
			this.setYYYY(1970);
		}
		try {
			this.setMM(mm);
		} catch (InvalidMMException e) {
			System.out.println(e.getMessage());
			this.setMM(1);
		}
		try {
			this.setDD(dd);
		} catch (InvalidDDException e) {
			System.out.println(e.getMessage());
			this.setDD(1);
		}
	}

	public int getDD() {
		return this.dd;
	}

	public void setDD(int dd) {
		if (dd < 1) {
			throw new InvalidDDException("Giorno (" + dd + ") non valido!");
		}

		int minDD = 1;
		int maxDD = 0;

		if (this.mm == 4 || this.mm == 6 || this.mm == 9 || this.mm == 11) {
			maxDD = 30;
		}
		else if (this.mm == 2) {
			maxDD = 28;
		}
		else {
			maxDD = 31;
		}

		if (dd > maxDD) {
			throw new InvalidDDException("Giorno (" + dd + ") non valido!");
		}

		this.dd = dd;
	}

	public int getMM() {
		return this.mm;
	}

	public void setMM(int mm) {
		if (mm < 1 || mm > 12) {
			throw new InvalidMMException("Mese (" + mm + ") non valido!");
		}
		this.mm = mm;
	}

	public int getYYYY() {
		return this.yyyy;
	}

	public void setYYYY(int yyyy) {
		if (yyyy <= 0) {
			throw new InvalidYYYYException("Anno (" + yyyy + ") non valido!");
		}
		this.yyyy = yyyy;
	}

	@Override
	public String toString() {
		return this.dd + "-" + this.mm + "-" + this.yyyy;
	}
}

public class Esercizio26 {
	public static void main(String [] args) {
		MyDate d = new MyDate(1, 1, 2000);
		System.out.println(d);

		d = new MyDate(32, 1, 2000);
		System.out.println(d);

		d = new MyDate(1, 13, 2000);
		System.out.println(d);

		d = new MyDate(1, 1, -1);
		System.out.println(d);
	}
}

