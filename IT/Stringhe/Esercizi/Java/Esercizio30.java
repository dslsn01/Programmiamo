/* file Esercizio30.java */

import java.io.Console;
import java.util.Scanner;
import java.util.regex.Pattern;
import java.util.regex.Matcher;

public class Esercizio30 {
	public static void main(String [] args) {
		System.out.println("Programmiamo un client di posta elettronica.");

		// destinatario
		String dest = "";

		// oggetto
		String obj = "";

		// corpo della mail
		String body = "";

		// eventuale allegato
		String att = "";

		boolean exit = false;

		System.out.println("From: joebloggs@programmiamo.com");
		Console input = System.console();

		String r = "[\\w\\.]+@[\\w]+\\.[\\w]{2,}";
		Pattern mailPattern = Pattern.compile(r);

		Pattern attPattern = Pattern.compile("alleg(at)?o", Pattern.CASE_INSENSITIVE);

		while (!exit) {
			if (dest.isEmpty()) {
				String _dest = input.readLine("To: ");
				if (!mailPattern.matcher(_dest).matches()) continue;
				dest = _dest;
			}

			if (obj.isEmpty()) {
				String _obj = input.readLine("Oggetto: ");
				obj = !_obj.isEmpty() ? _obj : " ";
				/*
				if (!obj.isEmpty()) obj = _obj;
				else {
					String placeHolder = "<nessun oggetto>";
					System.out.print(placeHolder);
				}
				*/
			}

			if (body.isEmpty()) {
				System.out.println("------- Messaggio -------" + System.lineSeparator());
				// String _body = input.readLine();
				Scanner sc = new Scanner(input.reader());
				StringBuilder sb = new StringBuilder();

				// si chiude con CTRL+D
				while (sc.hasNextLine()) {
					sb.append(sc.nextLine());
				}

				String _body = sb.toString();
				body = !_body.isEmpty() ? _body : " ";
				System.out.println(System.lineSeparator() + "-------------------------");
			}

			System.out.println("\"y\" - invia la mail" + System.lineSeparator() + "\"a\" - aggiungi un allegato" + System.lineSeparator() + "\"q\" - esci");
			String buf1 = input.readLine();
			char opt = !buf1.isEmpty() ? Character.toLowerCase(buf1.charAt(0)) : Character.MIN_VALUE;

			if (opt == 'y') {
				if (att.isEmpty()) {
					Matcher matcher1 = attPattern.matcher(obj);
					Matcher matcher2 = attPattern.matcher(body);

					if (matcher1.find() || matcher2.find()) {
						System.out.println("Forse vuoi allegare qualcosa. Inviare?" + System.lineSeparator() + "\"s\" - invia senza allegati" + System.lineSeparator() + "\"n\" - torna alla mail");
						String buf2 = input.readLine();
						char c = !buf2.isEmpty() ? Character.toLowerCase(buf2.charAt(0)) : 'n';
						if (c != 's') continue;
					}
				}

				System.out.println("Messaggio inviato.");
			}
			else if (opt == 'a') {
				String _att = input.readLine("File da allegare: ");
				if (_att.isEmpty()) continue;
				att = _att;
				System.out.println(System.lineSeparator() + "Caricamento di \"" + att + "\"...");
				System.out.println("####### 100% completato #######" + System.lineSeparator());
				continue;
			}

			exit = true;
		}
	}
}

