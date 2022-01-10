/* file Esercizio4.java */

import java.awt.Dimension;
import javax.swing.JFrame;
import javax.swing.ImageIcon;

public class Esercizio4 {
	public static void main(String [] args) {
		JFrame frame = new JFrame();

		frame.setSize(new Dimension(150, 100));

		ImageIcon icon = new ImageIcon("img/icon.gif");
		frame.setIconImage(icon.getImage());

		frame.setTitle("Icona");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
	}
}

