/* file Hashing.java */

import java.util.Map;
import java.util.HashMap;
import java.util.Arrays;

/* la classe Car rappresenta un'automobile */

class Car {
	/* identifichiamo ogni auto dal numero di telaio e dal numero di targa */
	private String vin;
	private String licensePlate;

	public Car(String vin, String licensePlate) {
		setVin(vin);
		setLicensePlate(licensePlate);
	}

	public void setVin(String vin) {
		this.vin = vin;
	}

	public String getVin() {
		return this.vin;
	}

	public void setLicensePlate(String licensePlate) {
		this.licensePlate = licensePlate;
	}

	public String getLicensePlate() {
		return this.licensePlate;
	}

	@Override
	public String toString() {
		return "Auto con n. di telaio " + this.vin + " e targa " + this.licensePlate;
	}

	/* due auto sono uguali se e solo se hanno lo stesso numero di telaio e la stessa targa, ossia se sono la stessa auto */
	@Override
	public boolean equals(Object obj) {
		if (!(obj instanceof Car)) {
			return false;
		}
		Car other = (Car)obj;
		boolean result = (this.vin == other.getVin() && this.licensePlate == other.getLicensePlate());

		return result;
	}

	/* il metodo hashCode() restituisce l'hash del V.I.N. e del numero di targa */
	@Override
	public int hashCode() {
		/* calcola l'hash complessivo di targa e numero di telaio, e moltiplica il risultato per una costante prima, per migliorare le prestazioni */
		final int prime = 31;
		int result = 1;
		String [] hash = new String[]{this.vin, this.licensePlate};
		result = prime * result + Arrays.hashCode(hash);
		return result;
	}
}

class Env {
	public static void main(String [] args) {
		/* crea tre nuove auto */

		Car car1 = new Car("1G2ZG58B974137936", "ALX L41");
		Car car2 = new Car("JNRAS08U87X828756", "ESA 827");
		Car car3 = new Car("1FTYR45E24P633565", "30-3930M");

		/* verifica l'uguaglianza tra automobili */

		Car car1copy = new Car("1G2ZG58B974137936", "ALX L41");

		System.out.println("L'auto originale è uguale alla sua copia? " + (car1.equals(car1copy)));

		/* crea tre piloti */

		String driver1 = "Niki Lauda";
		String driver2 = "Nelson Piquet";
		String driver3 = "Nigel Mansell";

		HashMap<Car, String> map = new HashMap<Car, String>();
		
		map.put(car1, driver1);
		map.put(car2, driver2);
		map.put(car3, driver3);
		
		for (Map.Entry<Car, String> pair : map.entrySet()) {
			System.out.println("Veicolo: " + pair.getKey() + ", Pilota: " + pair.getValue());
		}

		/* recupera il pilota associato all'auto */

		if (map.containsKey(car1)) {
			String value = map.get(car1);
			System.out.println("Trovata " + car1 + ", il suo pilota è: " + value);
		}
		else {
			System.out.println("Automobile non trovata!");
		}
	}
}

