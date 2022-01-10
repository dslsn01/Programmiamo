/* file Contact.java */ 

package programmiamo.ind;

import java.awt.Dimension;
import java.awt.GridLayout;
import java.awt.BorderLayout;
import javax.swing.JPanel;
import javax.swing.JLabel;
import javax.swing.Box;
import javax.swing.BoxLayout;

public class Contact extends JPanel {
	public JLabel name;
	public JLabel surname;
	public JLabel addr;
	public JLabel pnum;
	public JLabel email;

	public Contact(String name, String surname, String addr, String pnum, String email) {
		/* crea cinque etichette di testo non editabile */

		this.name = new JLabel(name);
		this.surname = new JLabel(surname);
		this.addr = new JLabel(addr);
		this.pnum = new JLabel(pnum);
		this.email = new JLabel(email);

		/* crea il pannello intermedio */

		JPanel panel = new JPanel();

		/* imposta le dimensioni del pannello intermedio */

		Dimension sz = new Dimension(400, 300);
		panel.setPreferredSize(sz);
		panel.setMaximumSize(sz);
		panel.setMinimumSize(sz);

		/* imposta il gestore di layout del pannello intermedio creando una griglia di tre righe e due colonne */

		panel.setLayout(new GridLayout(3, 2));

		/* aggiunge le etichette di testo al pannello intermedio */

		panel.add(this.name);
		panel.add(this.surname);
		panel.add(this.addr);
		panel.add(this.pnum);
		panel.add(this.email);

		Box box = new Box(BoxLayout.Y_AXIS);

		box.add(Box.createVerticalGlue());
		box.add(panel);
		box.add(Box.createVerticalGlue());

		/* imposta il layout manager, e aggiunge il pannello intermedio */

		this.setLayout(new BorderLayout());
		this.add(box);
	}
}

