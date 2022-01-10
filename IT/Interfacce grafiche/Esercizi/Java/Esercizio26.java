/* file Esercizio26.java */

import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.RenderingHints;
import java.awt.Polygon;
import javax.swing.JFrame;
import javax.swing.JPanel;
import java.util.List;
import java.util.ArrayList;

public class Esercizio26 {
	private static class PCanvas extends JPanel {
		private List<Polygon> ngons = new ArrayList<>();

		public PCanvas() {
			super(true);
			int w = 400;
			int h = 400;

			for (int i = 0; i < 13; i++) {
				addPolygon(w, h, i);
			}

			setPreferredSize(new Dimension(w, h));
		}

		private void addPolygon(int width, int height, int nVertx) {
			int r = width / 2;
			int x0 = r;
			int y0 = height / 2;
			int [] x_coords = new int[nVertx];
			int [] y_coords = new int[nVertx];

			double thetaI = 2 * Math.PI / nVertx;
			double theta = nVertx % 2 == 0 ? thetaI : -Math.PI/2;

			for (int i = 0; i < nVertx; i++) {
				double x = x0 + r * Math.cos(theta);
				double y = y0 + r * Math.sin(theta);
				x_coords[i] = (int) x;
				y_coords[i] = (int) y;
			
				theta += thetaI;
			}

			Polygon p = new Polygon(x_coords, y_coords, nVertx);
			ngons.add(p);
		}

		@Override
		public void paintComponent(Graphics g) {
			Graphics2D g2d = (Graphics2D) g;
			g2d.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);

			for (Polygon p : ngons) {
				g2d.drawPolygon(p);
			}
		}
	}

	public static void main(String [] args) {
		JFrame frame = new JFrame();
		frame.add(new PCanvas());
		frame.pack();
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
	}
}

