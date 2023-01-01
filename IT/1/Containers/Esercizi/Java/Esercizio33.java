/* file Esercizio33.java */

class Submarine {
	public <T> void emb(T sailor) {
		System.out.println("Benvenuto a bordo, " + sailor + "!");
	}
}

class Sailor {
	private String name;

	public Sailor(String name) {
		this.name = name;
	}

	@Override
	public String toString() {
		return name;
	}
}

class Pass {
	private String name;

	public Pass(String name) {
		this.name = name;
	}

	@Override
	public String toString() {
		return name;
	}
}

class Attn {
	private String name;

	public Attn(String name) {
		this.name = name;
	}

	@Override
	public String toString() {
		return name;
	}
}

public class Esercizio33 {
	public static void main(String [] args) {
		Submarine nautilus = new Submarine();

		Sailor s = new Sailor("Capitano Nemo");
		Pass p1 = new Pass("Pierre Aronnax");
		Attn a = new Attn("Conseil");
		Pass p2 = new Pass("Ned Land");

		nautilus.emb(s);
		nautilus.emb(p1);
		nautilus.emb(a);
		nautilus.emb(p2);
	}
}

