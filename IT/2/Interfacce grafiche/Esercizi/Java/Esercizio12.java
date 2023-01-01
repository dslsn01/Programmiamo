/* file Esercizio12.java */

import javax.swing.JFrame;
import javax.swing.JButton;
import javax.swing.JLabel;

public class Esercizio12 {
	public static void main(String [] args) {
		JFrame frame = new JFrame();

		JButton button = new JButton("Click");
		frame.add(button);
		frame.pack();

		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
	}
}

