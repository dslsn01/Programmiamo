/* file Pair.java */

public class Pair {
	private int a;
	private char b;

	public Pair(int a, char b) {
		this.a = a;
		this.b = b;
	}

	public Integer getA() {
		return this.a;
	}

	public void setA(Integer a) {
		this.a = a;
	}

	public char getB() {
		return this.b;
	}

	public void seB(char b) {
		this.b = b;
	}

	@Override
	public String toString() {
		return "(" + this.a + ", '" + this.b + "')";
	}
}

