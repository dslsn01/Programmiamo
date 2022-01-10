/* file Esercizio18.java */

import javax.swing.JFrame;
import javax.swing.JMenuBar;
import javax.swing.JMenu;
import javax.swing.JMenuItem;
import javax.swing.JPanel;
import javax.swing.BoxLayout;
import javax.swing.JLabel;
import javax.swing.JTextArea;
import javax.swing.JScrollPane;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.event.*;

public class Esercizio18 extends JFrame {
	private JTextArea text;

	public Esercizio18() {
		this.setTitle("Testa o croce?");
		JMenu fileMenu = new JMenu("File");
		JMenuItem exit = new JMenuItem("Esci");
		JMenuItem menu1 = new JMenuItem("Testa");
		JMenuItem menu2 = new JMenuItem("Croce");

		JMenuBar menuBar = new JMenuBar();

		fileMenu.add(menu1);
		fileMenu.add(menu2);
		fileMenu.add(exit);

		menuBar.add(fileMenu);
		this.setJMenuBar(menuBar);

		exit.addActionListener( new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				System.exit(0);
			}
		});

		menu1.addActionListener( new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				Esercizio18.this.text.append("Testa\n");
			}
		});

		menu2.addActionListener( new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				Esercizio18.this.text.append("Croce\n");
			}
		});

		text = new JTextArea();

		JLabel label = new JLabel("Lancia la monetina con il menu a tendina.");
		label.setFont(new Font(label.getFont().getName(), Font.PLAIN, 11));
		JPanel panel = new JPanel();
		panel.add(label);

		this.setLayout(new BoxLayout(this.getContentPane(), BoxLayout.Y_AXIS));

		JScrollPane scroll = new JScrollPane(text);
		scroll.setPreferredSize(new Dimension(280, 200));

		this.getContentPane().add(scroll);
		this.getContentPane().add(panel);
		this.pack();
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setVisible(true);
	}

	public static void main(String [] args) {
		 new Esercizio18();
	}
}

