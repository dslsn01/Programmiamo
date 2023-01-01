/* file Esercizio6.java */

interface Baz {
	void baz();
}

class Foo implements Baz {
	@Override
	public void baz() {
		System.out.println("Foo");
	}
}

class Bar implements Baz {
	@Override
	public void baz() {
		throw new UnsupportedOperationException("Operazione non supportata!");
	}
}

public class Esercizio6 {
	public static void main(String [] args) {
		Baz [] objs = {new Foo(), new Bar(), new Foo()};

		for (Baz obj : objs) {
			try {
				obj.baz();
			}
			catch (UnsupportedOperationException e) {
				System.out.println(e.getMessage());
			}
		}

		System.out.println("Fine del programma.");
	}
}

