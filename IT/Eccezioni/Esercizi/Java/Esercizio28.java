/* file Esercizio28.java */

import java.io.Console;

class ATMAuthException extends IllegalArgumentException {
	public ATMAuthException(String message) {
		super(message);
	}
}

class ATM {
	private boolean login = false;
	private boolean run = true;
	private double balance = 1500;
	private Console console = System.console();

	private void enterPin() throws ATMAuthException {
		if (!this.login) {
			String pin = console.readLine("Inserisci il P.I.N.: ");

			if (pin.equals("12345")) {
				this.login = true;
			}
			else {
				throw new ATMAuthException("PIN non valido!");
			}
		}
	}

	public ATM() {
		System.out.println("+++++++ Sportello ATM +++++++");

		while (this.run) {
			System.out.println("\nOperazioni disponibili:\n");
			System.out.println("1. Saldo");
			System.out.println("2. Prelievo");
			System.out.println("3. Deposito");
			System.out.println("4. Esci\n");

			String oper = console.readLine("Scegli l'operazione (1, 2, 3, 4): ");

			try {
				if (oper.equals("1")) {
					this.enterPin();
					System.out.println("\n---------------------");
					System.out.println("Saldo corrente: " + this.balance + " euro.");
					System.out.println("---------------------");
				}
				else if (oper.equals("2")) {
					this.enterPin();
					String s = console.readLine("Importo da prelevare: ");
					double cash = Double.parseDouble(s);
					this.balance -= cash;

					System.out.println("\n---------------------");
					System.out.println("Hai prelevato " + cash + " euro. Saldo corrente: " + this.balance);
					System.out.println("---------------------");
				}
				else if (oper.equals("3")) {
					this.enterPin();
					String s = console.readLine("Importo da versare: ");
					double cash = Double.parseDouble(s);
					this.balance += cash;

					System.out.println("\n---------------------");
					System.out.println("Hai versato " + cash + " euro. Saldo corrente: " + this.balance);
					System.out.println("---------------------");
				}
				else if (oper.equals("4")) {
					System.out.println("Grazie di avere utilizzato i nostri servizi ATM.");
					this.run = false;
				}
				else {
					System.out.println("Operazione sconosciuta!");
				}
			}
			catch (IllegalArgumentException e) {
				System.out.println("\nxxxxxxxxxxxxxxxxxxxxx");
				System.out.println(e.getMessage());
				System.out.println("xxxxxxxxxxxxxxxxxxxxx");
			}
		}
	}
}

public class Esercizio28 {
	public static void main(String [] args) {
		ATM atm = new ATM();
	}
}

