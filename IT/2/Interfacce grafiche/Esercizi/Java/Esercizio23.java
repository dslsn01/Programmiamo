/* file Esercizio23.java */

import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.RenderingHints;
import javax.swing.JFrame;
import javax.swing.JPanel;

public class Esercizio23 extends JFrame {
	public Esercizio23() {
		this.add(	new JPanel() {
			@Override
			public void paintComponent(Graphics o) {
				Graphics2D g = (Graphics2D) o;
				g.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
				g.drawOval(10, 10, 80, 80);
			}
		});

		this.setSize(new Dimension(100, 140));
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setVisible(true);
	}

	public static void main(String [] args) {
		new Esercizio23();
	}
}

