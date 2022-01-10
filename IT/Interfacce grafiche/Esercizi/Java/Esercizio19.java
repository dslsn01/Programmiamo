/* file Esercizio19.java */

import javax.swing.JFrame;
import javax.swing.JComboBox;
import javax.swing.JLabel;
import java.awt.Dimension;
import java.awt.GridBagLayout;
import java.awt.GridBagConstraints;
import java.awt.event.*;

public class Esercizio19 extends JFrame implements ItemListener {
	private JLabel label;

	public Esercizio19() {
		this.setTitle("Scegli la tua lingua");
		this.label = new JLabel("Ciao!");
		String [] items = {"italiano", "inglese"};
		JComboBox<String> lang = new JComboBox<String>(items);
		lang.addItemListener(this);

		this.getContentPane().setLayout(new GridBagLayout());
		GridBagConstraints c = new GridBagConstraints();
		c.gridx = 0;
		c.gridy = 0;

		this.add(label, c);

		c.gridy = 1;
		this.add(lang, c);

		this.setSize(new Dimension(200, 100));
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setVisible(true);
	}

	@Override
	public void itemStateChanged(ItemEvent e) {
		String item = (String)e.getItem();
		if (item.equals("italiano")) {
			this.label.setText("Ciao!");
		}
		if (item.equals("inglese")) {
			this.label.setText("Hello!");
		}
	}

	public static void main(String [] args) {
		new Esercizio19();
	}
}

