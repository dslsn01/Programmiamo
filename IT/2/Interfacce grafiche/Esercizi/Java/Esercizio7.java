/* file Esercizio7.java */

import javax.swing.JFrame;
import javax.swing.BoxLayout;
import javax.swing.JLabel;

public class Esercizio7 {
	public static void main(String [] args) {
		JFrame frame = new JFrame();
		JLabel label1 = new JLabel("Un'etichetta");
		JLabel label2 = new JLabel("Un'altra etichetta");

		frame.getContentPane().setLayout(new BoxLayout(frame.getContentPane(), BoxLayout.Y_AXIS));

		frame.add(label1);
		frame.add(label2);
		frame.pack();

		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
	}
}

