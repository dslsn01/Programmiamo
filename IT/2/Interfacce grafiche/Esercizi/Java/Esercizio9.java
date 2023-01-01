/*
file Esercizio9.java
passare un parametro da linea di comando, per esempio
javac Esercizio9.java
java Esercizio9.java 'Ciao, mondo!' (Attenzione ai singoli apici) 
*/

import javax.swing.JFrame;
import javax.swing.JLabel;

public class Esercizio9 {
	public static void main(String [] args) {
		String arg = args.length > 0 ? args[0] : "La tua stringa";

		JFrame frame = new JFrame();
		JLabel label = new JLabel(arg);

		frame.add(label);
		frame.pack();

		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
	}
}

