/* file Esercizio25.java */

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.RenderingHints;
import javax.swing.JFrame;
import javax.swing.JPanel;

public class Esercizio25 extends JFrame {
	public Esercizio25() {
		this.add(	new JPanel() {
			@Override
			public void paintComponent(Graphics o) {
				Graphics2D g = (Graphics2D) o;
				g.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
				g.setColor(Color.RED);
				g.fillOval(10, 10, 80, 80);
				g.setColor(Color.GREEN);
				g.fillOval(20, 20, 60, 60);
				g.setColor(Color.BLUE);
				g.fillOval(30, 30, 40, 40);
			}
		});

		this.setSize(new Dimension(100, 140));
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setVisible(true);
	}

	public static void main(String [] args) {
		 new Esercizio25();
	}
}

