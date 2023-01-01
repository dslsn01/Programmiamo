/* file Esercizio14.java */

class Engine {
	private int cc;

	public Engine(int cc) {
		this.cc = cc;
	}
}

class Car {
	private String model;
	private String vin;
	private String plate;
	private Engine engine;

	public Car(String model, String vin, String plate, Engine engine) {
		this.model = model;
		this.vin = vin;
		this.plate = plate;
		this.engine = engine;
	}
}

