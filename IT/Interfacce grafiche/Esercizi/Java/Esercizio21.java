/* file Esercizio21.java */

import javax.swing.JFrame;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.event.*;

public class Esercizio21 extends JFrame {
	private Color _default;

	public Esercizio21() {
		this._default = getBackground();

		this.addMouseListener( new MouseAdapter() {
			@Override
			public void mouseEntered(MouseEvent e) {
				Esercizio21.this.getContentPane().setBackground(Color.GREEN);
			}

			@Override
			public void mouseExited(MouseEvent e) {
				Esercizio21.this.getContentPane().setBackground(Esercizio21.this._default);
			}
		});

		this.setSize(new Dimension(150, 150));
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setVisible(true);
	}

	public static void main(String [] args) {
		 new Esercizio21();
	}
}

