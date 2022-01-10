/* file Esercizio20.java */

import javax.swing.JFrame;
import javax.swing.JComboBox;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.GridBagLayout;
import java.awt.GridBagConstraints;
import java.awt.event.*;

public class Esercizio20 extends JFrame implements ItemListener {
	private Color _default;

	public Esercizio20() {
		this._default = getBackground();
		String [] items = {"default", "rosso", "verde", "blu"};
		JComboBox<String> color = new JComboBox<String>(items);
		color.addItemListener(this);

		this.getContentPane().setLayout(new GridBagLayout());
		GridBagConstraints c = new GridBagConstraints();
		c.gridx = 0;
		c.gridy = 1;
		this.add(color, c);

		this.setSize(new Dimension(200, 100));
		this.setTitle("Scegli il colore");
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setVisible(true);
	}

	@Override
	public void itemStateChanged(ItemEvent e) {
		String item = (String)e.getItem();
		if (item.equals("default")) {
			this.getContentPane().setBackground(this._default);
		}
		if (item.equals("rosso")) {
			this.getContentPane().setBackground(Color.RED);
		}
		if (item.equals("verde")) {
			this.getContentPane().setBackground(Color.GREEN);
		}
		if (item.equals("blu")) {
			this.getContentPane().setBackground(Color.BLUE);
		}
	}

	public static void main(String [] args) {
		 new Esercizio20();
	}
}

