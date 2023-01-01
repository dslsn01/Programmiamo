/* file Esercizio21.java */

class Factory {
	private static int instances = 0;

	public static int getInstances() {
		return instances;
	}

	public static Smartphone newSmartphone(String model) {
		instances += 1;
		return new Smartphone(model);
	}
}

class Smartphone {
	private String model;

	public Smartphone(String model) {
		this.model = model;
	}

	@Override
	public String toString() {
		return this.model;
	}
}

public class Esercizio21 {
	public static void main(String [] args) {
		Smartphone iphone = Factory.newSmartphone("iPhone");
		Smartphone samsung = Factory.newSmartphone("Samsung");
		Smartphone huawei = Factory.newSmartphone("Huawei");

		System.out.println("Prodotti " + Factory.getInstances() + " nuovi smartphone.");

		System.out.println(iphone);
		System.out.println(samsung);
		System.out.println(huawei);
	}
}

