/* file ExceptionPropagation.java */

public class ExceptionPropagation {
	/* il metodo statico propagate() solleva un'eccezione generica, propagata all'esterno con la parola chiave throws */

	static void propagate() throws Exception {
		throw new Exception("Sollevata un'eccezione!");
	}

	/* il metodo main() invoca il metodo propagate() e gestisce l'eccezione */

	public static void main(String [] args) {
		try {
			propagate();
		} 
		catch (Exception e) {
			e.printStackTrace();
		}

		System.out.println("Fine del programma.");
	}
}

