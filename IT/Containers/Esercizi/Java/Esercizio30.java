/* file Esercizio30.java */

import java.io.Console;
import java.util.Map;
import java.util.Map.Entry;
import java.util.HashMap;

public class Esercizio30 {
	public static void main(String [] args) {
		Map<String, String> messages = new HashMap<String, String>();

		messages.put("it", "Benvenuto!");
		messages.put("en", "Welcome!");
		messages.put("en-us", "Welcome!");

		String lang = System.console().readLine("Seleziona la tua lingua: ");

		if (messages.containsKey(lang)) {
			System.out.println(messages.get(lang));
		}
		else {
			if (lang.isEmpty()) {
				System.out.println(messages.get("en"));
				return;
			}

			Console console = System.console();
			String s = console.readLine("Lingua sconosciuta!" + System.lineSeparator() + "Aggiungere una nuova lingua? s/n: ");

			if (s.equalsIgnoreCase("s")) {
				String msg = console.readLine("Nuovo messaggio di benvenuto: ");
				messages.put(lang, msg);
				System.out.println(messages.get(lang));

				System.out.println("Messaggi di benvenuto aggiornati.");

				for (Entry<String, String> entry : messages.entrySet()) {
					System.out.println(entry.getKey() + "=" + entry.getValue());
				}
			}
		}
	}
}

