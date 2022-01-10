/* file Esercizio15.java */

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

	public String getModel() {
		return this.model;
	}

	public void setModel(String model) {
		this.model = model;
	}

	public String getPlate() {
		return this.plate;
	}

	public void setPlate(String plate) {
		this.plate = plate;
	}

	public String getVin() {
		return this.vin;
	}

	public void setVin(String vin) {
		this.vin = vin;
	}

	public Engine getEngine() {
		return this.engine;
	}

	public void setEngine(Engine engine) {
		this.engine = engine;
	}
}

