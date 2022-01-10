/* file Esercizio11.java */

import java.awt.Dimension;
import javax.swing.JFrame;

public class Esercizio11 extends JFrame {
	public Esercizio11() {
		this.setSize(new Dimension(150, 100));
		this.setTitle("Titolo");
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setVisible(true);
	}

	public static void main(String [] args) {
		new Esercizio11();
	}
}

