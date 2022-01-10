/* file Esercizio28.java */

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.RenderingHints;
import java.awt.Polygon;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import javax.swing.JFrame;
import javax.swing.JPanel;
import java.util.List;
import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;
import java.util.Random;

public class Esercizio28 {
	private static class PCanvas extends JPanel implements MouseListener {
		private List<Integer> xCoords = new ArrayList<>();
		private List<Integer> yCoords = new ArrayList<>();
		private Color [] colors = new Color[] { Color.RED, Color.ORANGE, Color.YELLOW, Color.GREEN, Color.BLUE, Color.CYAN };
		// mappa dei poligoni, associati ai colori
		private Map<Polygon, Color> ngons = new HashMap<>();

		public PCanvas() {
			super(true);
			addMouseListener(this);
			setPreferredSize(new Dimension(400, 400));
		}

		@Override
		public void mouseClicked(MouseEvent e) {}

		@Override
		public void mousePressed(MouseEvent e) {}

		@Override
		public void mouseReleased(MouseEvent e) {
			int btn = e.getButton();
			if (btn == MouseEvent.BUTTON1) {
				xCoords.add(e.getX());
				yCoords.add(e.getY());
			}
			else if (btn == MouseEvent.BUTTON3) {
				int [] x_coords = new int[xCoords.size()];
				for (int i = 0; i < xCoords.size(); i++) {
					x_coords[i] = xCoords.get(i);
				}

				int [] y_coords = new int[yCoords.size()];
				for (int i = 0; i < yCoords.size(); i++) {
					y_coords[i] = yCoords.get(i);
				}
				Random rand = new Random();
				// seleziona un colore a caso
				Color color = colors[rand.nextInt(colors.length)];
				Polygon poly = new Polygon(x_coords, y_coords, x_coords.length);
				ngons.put(poly, color);

				xCoords.clear();
				yCoords.clear();
				repaint();
			}
		}

		@Override
		public void mouseEntered(MouseEvent e) {}

		@Override
		public void mouseExited(MouseEvent e) {}

		@Override
		public void paintComponent(Graphics g) {
			Graphics2D g2d = (Graphics2D) g;
			g2d.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);

			for (Map.Entry<Polygon, Color> e : ngons.entrySet()) {
				Polygon p = e.getKey();
				Color c = e.getValue();
				g2d.setColor(c);
				g2d.fillPolygon(p);
			}
		}
	}

	public static void main(String [] args) {
		JFrame frame = new JFrame();
		frame.add(new PCanvas());
		frame.pack();
		frame.setTitle("Disegna una serie di poligoni");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
	}
}

