/* file Esercizio27.java */

import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.RenderingHints;
import java.awt.Shape;
import java.awt.geom.Ellipse2D;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import javax.swing.JFrame;
import javax.swing.JPanel;
import java.util.List;
import java.util.ArrayList;

public class Esercizio27 {
	private static class CCanvas extends JPanel implements MouseListener {
		private int x0 = -1;
		private int y0 = -1;
		private List<Shape> cc = new ArrayList<>();

		public CCanvas() {
			super(true);
			addMouseListener(this);
			setPreferredSize(new Dimension(400, 400));
		}

		@Override
		public void mouseClicked(MouseEvent e) {}

		@Override
		public void mousePressed(MouseEvent e) {
			this.x0 = e.getX();
			this.y0 = e.getY();
		}

		@Override
		public void mouseReleased(MouseEvent e) {
			int x1 = e.getX();
			int y1 = e.getY();
			// raggio della circonferenza
			double r = Math.sqrt(Math.pow((double) x1 - this.x0, 2.0) + Math.pow((double) y1 - this.y0, 2.0));
			double _x0 = x0 - r;
			double _y0 = y0 - r;
			Shape circle = new Ellipse2D.Double(_x0, _y0, r*2, r*2);
			cc.add(circle);

			this.repaint();
		}

		@Override
		public void mouseEntered(MouseEvent e) {}

		@Override
		public void mouseExited(MouseEvent e) {}

		@Override
		public void paintComponent(Graphics g) {
			Graphics2D g2d = (Graphics2D) g;
			g2d.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);

			for (Shape s : cc) {
				g2d.draw(s);
			}
		}
	}

	public static void main(String [] args) {
		JFrame frame = new JFrame();
		frame.add(new CCanvas());
		frame.pack();
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
	}
}

