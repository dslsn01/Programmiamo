/* file GenericParams.java */

interface Vehicle {
	void startEngine();
}

/* utilizziamo la notazione <? extends TYPE> per poter accedere ai metodi del tipo */

class Garage {
	public <T extends Vehicle> void checkup(T vehicle) {
		vehicle.startEngine();
	}
}

class Car implements Vehicle {
	@Override
	public void startEngine() {
		System.out.println("Avvio l'automobile!");
	}
}

class Moto implements Vehicle {
	@Override
	public void startEngine() {
		System.out.println("Avvio la moto!");
	}
}

public class GenericParams {
	public static void main(String [] args) {
		Garage garage = new Garage();

		Car car = new Car();
		garage.checkup(car);

		Moto moto = new Moto();
		garage.checkup(moto);
	}
}

