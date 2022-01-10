/* file Esercizio18.java */

class Engine {
	private int cc;

	public Engine(int cc) {
		this.cc = cc;
	}

	@Override
	public String toString() {
		return "motore di " + this.cc + " centimetri cubi";
	}
}

class Vehicle {
	private Engine engine;

	public Vehicle(Engine e) {
		setEngine(e);
	}

	public Engine getEngine() {
		return this.engine;
	}

	public void setEngine(Engine e) {
		this.engine = e;
	}
}

class Car extends Vehicle {
	private String model;
	private String vin;
	private String plate;

	public Car(String model, String vin, String plate, Engine e) {
		super(e);
		setModel(model);
		setVin(vin);
		setPlate(plate);
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

	@Override
	public String toString() {
		return this.model + ", targa \"" + this.plate + "\", n. telaio \"" + this.vin + "\", " + this.getEngine().toString();
	}

}

class Truck extends Vehicle {
	public Truck(Engine e) {
		super(e);
	}

	@Override
	public String toString() {
		return "Camion con " + this.getEngine().toString();
	}
}

class Tractor extends Vehicle {
	public Tractor(Engine e) {
		super(e);
	}

	@Override
	public String toString() {
		return "Trattore con " + this.getEngine().toString();
	}
}

public class Esercizio18 {
	public static void main(String [] args) {
		Car fiat500 = new Car("Fiat 500", "1G8AN12F04Z242828", "AS 123 DF", new Engine(1400));
		Car classeA = new Car("Mercedes Classe A", "2FZHAZBD21AH02482", "CA 128 TD", new Engine(1600));
		Car alfaGiulia = new Car("Alfa Romeo Giulia", "2G1115SL7F9174905", "EE 119 CA", new Engine(2000));

		System.out.println(fiat500);
		System.out.println(classeA);
		System.out.println(alfaGiulia);

		Truck truck = new Truck(new Engine(15000));
		Tractor tractor = new Tractor(new Engine(5800));

		System.out.println(truck);
		System.out.println(tractor);
	}
}

