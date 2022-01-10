/* file Esercizio22.java */

import javax.swing.JFrame;
import javax.swing.JLabel;
import java.awt.Dimension;
import java.awt.GridBagLayout;
import java.awt.GridBagConstraints;
import java.awt.Point;
import java.awt.event.*;

public class Esercizio22 extends JFrame {
	private JLabel coords;

	public Esercizio22() {
		this.coords = new JLabel("x = -1, y = -1");

		this.addMouseMotionListener( new MouseMotionListener() {
			@Override
			public void mouseMoved(MouseEvent e) {
				Point cursor = Esercizio22.this.getMousePosition();
				double x = cursor.getX();
				double y = cursor.getY();
				Esercizio22.this.coords.setText("x = " + x + ", y = " + y);
			}

			@Override
			public void mouseDragged(MouseEvent e) {}
		});

		this.getContentPane().setLayout(new GridBagLayout());
		GridBagConstraints c = new GridBagConstraints();
		c.gridx = 0;
		c.gridy = 0;

		this.add(coords, c);

		this.setSize(new Dimension(200, 100));
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setVisible(true);
	}

	public static void main(String [] args) {
		 new Esercizio22();
	}
}

