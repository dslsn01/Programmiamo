/* file GenericObj.java */

/* la classe generica GBox può contenere un regalo qualsiasi */

class GBox <T> {
	/* il tipo del parametro T generico viene stabilito durante la compilazione */
	private T gift;

	public GBox(T gift) {
		this.gift = gift;
	}

	public T unpack() { 
		return this.gift;
	}
}

class Toy {
	@Override
	public String toString() {
		return "giocattolo";
	}
}

class Holiday {
	@Override
	public String toString() {
		return "buono vacanza";
	}
}

public class GenericObj {
	public static void main(String [] args) {
		/* crea un pacco regalo per contenere un giocattolo */

		GBox<Toy> gift1 = new GBox<Toy>(new Toy());

		/* crea un pacco regalo per contenere un buono vacanza */

		GBox<Holiday> gift2 = new GBox<Holiday>(new Holiday());

		Toy toy = gift1.unpack();
		System.out.println("Ti regalo un " + toy + "!");

		Holiday holiday = gift2.unpack();
		System.out.println("Ti regalo un " + holiday + "!");
	}
}

