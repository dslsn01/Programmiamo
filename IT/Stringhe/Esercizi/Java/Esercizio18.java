/* file Esercizio18.java */

public class Esercizio18 {
	public static void main(String [] args) {
		String s = "David Bowman: 'Hal, apri la saracinesca esterna! Pronto Hal, mi ricevi? Pronto Hal, mi ricevi?'" + System.lineSeparator();
		s += "HAL 9000: 'Affermativo, David. Ti ricevo'." + System.lineSeparator();
		s += "David Bowman: 'Apri la saracinesca esterna, Hal'." + System.lineSeparator();
		s += "HAL 9000: 'Mi dispiace David, purtroppo non posso farlo'." + System.lineSeparator();
		s += "David Bowman: 'Qual è il motivo?'" + System.lineSeparator();
		s += "HAL 9000: 'Credo che tu lo sappia altrettanto bene quanto me'.";

		System.out.println(s);

		s = s.replace("'", "\"");

		System.out.println(System.lineSeparator() + "-> Sostituiamo i singoli apici con i doppi apici." + System.lineSeparator());

		System.out.println(s);
	}
}

