/* file MainFrame.java */

package programmiamo.ind;

import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JFrame;
import javax.swing.JMenuBar;
import javax.swing.JMenu;
import javax.swing.JMenuItem;
import javax.swing.JTabbedPane;
import javax.swing.JPanel;

public class MainFrame extends JFrame {
	private JTabbedPane tabs;

	public MainFrame() {
		/* crea il Notebook */

		tabs = new JTabbedPane();

		updateUI();

		JMenuBar menuBar = new JMenuBar();
		JMenu fileMenu = new JMenu("File");
		menuBar.add(fileMenu);

		/* aggiunge tre sottomenu al menu "file" */

		JMenuItem save = new JMenuItem("Nuovo");
		JMenuItem remove = new JMenuItem("Cancella");
		JMenuItem exit = new JMenuItem("Esci");

		fileMenu.add(save);
		fileMenu.add(remove);
		fileMenu.add(exit);

		/* gestisce il click sul menu "Nuovo" */

		save.addActionListener(	new ActionListener() {
			public void actionPerformed(ActionEvent evt) {
				;
			}
		});

		/* gestisce il click sul menu "Cancella" */ 

		remove.addActionListener(	new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				;
			}
		});

		/* gestisce il click sul menu "Esci" */ 

		exit.addActionListener(	new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				MainFrame.this.dispose();
			}
		});

		this.setJMenuBar(menuBar);
		this.add(tabs);
		this.setSize(new Dimension(640, 480));
		this.setTitle("Indirizzario");
		this.setVisible(true);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}

	/* crea le linguette nel Notebook */

	public void updateUI() {
		for (int counter = 1; counter < 4; counter++) {
			String pageName = "Pagina " + counter;
			tabs.addTab(pageName, new JPanel());
		}
	}
}

