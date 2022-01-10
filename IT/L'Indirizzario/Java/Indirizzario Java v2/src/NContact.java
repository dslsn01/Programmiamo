/* file NContact.java */

package programmiamo.ind;

import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.BoxLayout;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.JButton;

public class NContact extends JFrame {
	private MainFrame parent;

	public NContact(MainFrame parent) {
		this.parent = parent;

		/* crea cinque campi di testo editabile */

		JTextField name = new JTextField("Nome");
		JTextField surname = new JTextField("Cognome");
		JTextField addr = new JTextField("Indirizzo");
		JTextField pnum = new JTextField("Numero di telefono");
		JTextField email = new JTextField("E-mail");

		/* crea il pannello superiore */

		JPanel panel = new JPanel();

		/* imposta il layout manager del pannello intermedio, creando una griglia di tre righe e due colonne */

		panel.setLayout(new GridLayout(3, 2));

		/* aggiunge i campi di testo editabile al pannello superiore */

		panel.add(name);
		panel.add(surname);
		panel.add(addr);
		panel.add(pnum);
		panel.add(email);

		/* crea i pulsanti "Ok" e "Annulla" */

		JButton ok = new JButton("Ok");
		JButton cancel = new JButton("Annulla");

		/* aggiunge i due pulsanti a un nuovo pannello */

		JPanel buttons = new JPanel();

		buttons.add(ok);
		buttons.add(cancel);

		/* gestisce il click sul pulsante "Ok" */

		ok.addActionListener(	new ActionListener() {
			public void actionPerformed(ActionEvent e) { 
				;
			}
		});

		/* gestisce il click sul pulsante "Annulla" */
	
		cancel.addActionListener(	new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				NContact.this.dispose();
			}
		});

		this.getContentPane().setLayout(new BoxLayout(this.getContentPane(), BoxLayout.Y_AXIS));

		/* aggiunge i due pannelli alla finestra NContact */

		this.add(panel);
		this.add(buttons);
		this.pack();

		/* chiude la finestra NContact, lasciando aperta la finestra principale dell'applicazione */

		this.setTitle("Inserisci contatto");
		this.setVisible(true);
		this.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
	}
}

