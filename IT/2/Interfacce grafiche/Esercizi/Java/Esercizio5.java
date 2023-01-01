/* file Esercizio5.java */

import java.awt.Color;
import java.awt.Dimension;
import javax.swing.JFrame;

public class Esercizio5 {
	public static void main(String [] args) {
		JFrame frame = new JFrame();

		frame.setSize(new Dimension(150, 100));
		frame.setTitle("Titolo");
		frame.getContentPane().setBackground(Color.RED);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
	}
}

