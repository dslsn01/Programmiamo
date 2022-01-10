/* file EventHandling.java */

import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;

public class EventHandling extends JFrame {
	private JTextArea text;
	private JButton button;

	public EventHandling() {
		/* crea un'area di testo */

		text = new JTextArea();

		/* crea un pulsante */

		button = new JButton("Cliccami!");

		/* associa il gestore dell'evento click al pulsante */

		button.addActionListener( new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				EventHandling.this.text.append("Click!\n");
			}
		});

		/* crea un pannello intermedio per riposizionare il pulsante */

		JPanel panel = new JPanel();
		panel.add(button);

		/* aggiunge una barra di scorrimento per gestire il testo */

		JScrollPane scroll = new JScrollPane(text);
		scroll.setPreferredSize(new Dimension(280, 220));

		/* reimposta il layout manager della finestra per disporre le componenti in colonna */

		this.setLayout(new BoxLayout(this.getContentPane(), BoxLayout.Y_AXIS));

		this.getContentPane().add(scroll);
		this.getContentPane().add(panel);
		this.pack();
		this.setTitle("Ciao!");
		this.setVisible(true);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}

	public static void main(String [] args) {
		new EventHandling();
	}
}

