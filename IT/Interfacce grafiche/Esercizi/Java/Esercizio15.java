/* file Esercizio15.java */

import javax.swing.JFrame;
import javax.swing.JMenuBar;
import javax.swing.JMenu;
import javax.swing.JMenuItem;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Esercizio15 extends JFrame {
	public Esercizio15() {
		JMenu fileMenu = new JMenu("File");
		JMenuItem menu = new JMenuItem("Esci");
		fileMenu.add(menu);

		JMenuBar menuBar = new JMenuBar();
		menuBar.add(fileMenu);

		this.setJMenuBar(menuBar);

		menu.addActionListener( new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				System.exit(0);
			}
		});

		this.pack();
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setVisible(true);
	}

	public static void main(String [] args) {
		new Esercizio15();
	}
}

