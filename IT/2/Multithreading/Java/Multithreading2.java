/* file Multithreading2.java */

/* la classe MyThread rappresenta un Thread personalizzato che esegue un blocco di codice */

class MyThread extends Thread {
	@Override
	public void run() {
		System.out.println("Ciao, sono il " + this.getName() + "!");
	}
}

public class Multithreading2 {
	public static void main(String [] args) {
		/* crea due nuovi thread di tipo MyThread */

		MyThread t1 = new MyThread();
		MyThread t2 = new MyThread();

		/* abilita i nuovi thread per l'esecuzione */

		t1.start();
		t2.start();
	}
}

