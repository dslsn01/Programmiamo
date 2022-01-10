// https://stackoverflow.com/questions/22162398/how-to-set-a-background-picture-in-jpanel
/* file Esercizio10.java */

import javax.swing.JFrame;
import javax.swing.BoxLayout;
import javax.swing.JLabel;
import javax.swing.ImageIcon;

public class Esercizio10 {
	public static void main(String [] args) {
		JFrame frame = new JFrame();
		frame.setTitle("Immagine");

		ImageIcon img = new ImageIcon("img/image.gif");
		JLabel background = new JLabel(img);
		frame.add(background);

		frame.pack();
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
	}
}

