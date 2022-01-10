/* file Esercizio6.java */

import javax.swing.JFrame;
import javax.swing.JLabel;

public class Esercizio6 {
	public static void main(String [] args) {
		JFrame frame = new JFrame();
		JLabel label = new JLabel("La tua stringa");

		frame.add(label);
		frame.pack();

		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
	}
}

