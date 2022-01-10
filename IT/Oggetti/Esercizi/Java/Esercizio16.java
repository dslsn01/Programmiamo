/* file Esercizio16.java */

class Engine {
	private int cc;

	public Engine(int cc) {
		this.cc = cc;
	}

	@Override
	public String toString() {
		return "motore di "+ this.cc + " centimetri cubi";
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

	@Override
	public String toString() {
		String desc = this.model + ", targa: " + this.plate + ", n.telaio: " + this.vin + ", " + this.getEngine().toString();
		return desc;
	}
}

public class Esercizio16 {
	public static void main(String [] args) {
		Car fiat500 = new Car("Fiat 500", "1G8AN12F04Z242828", "AS 123 DF", new Engine(1400));
		Car classeA = new Car("Mercedes Classe A", "2FZHAZBD21AH02482", "CA 128 TD", new Engine(1600));
		Car alfaGiulia = new Car("Alfa Romeo Giulia", "2G1115SL7F9174905", "EE 119 CA", new Engine(2000));

		System.out.println(fiat500);
		System.out.println(classeA);
		System.out.println(alfaGiulia);
	}
}

