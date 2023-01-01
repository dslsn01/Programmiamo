/* file AbstractClass.java */

abstract class Vehicle {
	/* la classe astratta Vehicle dichiara il metodo astratto start(), che dovrà essere implementato dalle sottoclassi */

	public abstract void start();

	/* dichiara il metodo non astratto turn() */

	public void turn() {
		System.out.println("Cambio di direzione!");
	}
}

/* la classe concreta Train estende la classe astratta Vehicle e implementa il metodo astratto start() */

class Train extends Vehicle {
	@Override
	public void start() {
		System.out.println("Partenza dal binario 1!");
	}
}

/* la classe concreta Aircraft estende la classe astratta Vehicle e implementa il metodo astratto start() */

class Aircraft extends Vehicle {
	@Override
	public void start() {
		System.out.println("Decollo dalla pista!");
	}
}

class Env {
	public static void main(String [] args) {
		Train train = new Train();
		train.start();
		train.turn();

		Aircraft jumbo = new Aircraft();
		jumbo.start();
		jumbo.turn();
	}
}

