/* file GraphicHelloWorld.java */

import javax.swing.JFrame;
import javax.swing.JLabel;

public class GraphicHelloWorld {
	public static void main(String [] args) {
		/* crea la finestra principale */

		JFrame frame = new JFrame();

		/* crea un'etichetta di testo */

		JLabel label = new JLabel("Ciao, mondo!");

		/* aggiunge l'etichetta alla finestra principale */

		frame.add(label);

		/* ridimensiona il frame secondo la dimensione dell'etichetta */

		frame.pack();

		/* rende visibile il frame */

		frame.setVisible(true);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
}

