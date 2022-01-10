/* file GenericFunc.java */

/* la classe Receptionist non è generica, ma include il metodo generico registerP() */

class Receptionist {
	public <T> void registerP(T visitor) {
		System.out.println("Registro un " + visitor + ".");
	}
}

class Customer {
	@Override
	public String toString() {
		return "cliente";
	}
}

class Supplier {
	@Override
	public String toString() {
		return "fornitore";
	}
}

public class GenericFunc {
	public static void main(String [] args) {
		Receptionist receptionist = new Receptionist();

		Customer customer = new Customer();
		receptionist.registerP(customer);

		Supplier supplier = new Supplier();
		receptionist.registerP(supplier);
	}
}

