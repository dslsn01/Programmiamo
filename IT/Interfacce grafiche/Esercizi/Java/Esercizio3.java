/* file Esercizio3.java */

import java.awt.Dimension;
import javax.swing.JFrame;

public class Esercizio3 {
	public static void main(String [] args) {
		JFrame frame = new JFrame();

		frame.setSize(new Dimension(150, 100));
		frame.setLocationRelativeTo(null);
		frame.setTitle("Titolo");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
	}
}

