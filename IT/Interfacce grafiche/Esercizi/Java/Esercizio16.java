/* file Esercizio16.java */

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JTextArea;
import javax.swing.JScrollPane;
import java.awt.Dimension;
import java.awt.event.*;

public class Esercizio16 extends JFrame {
	private JTextArea text;
	private JButton button1;
	private JButton button2;

	public Esercizio16() {
		this.setTitle("Testa o croce?");
		text = new JTextArea();
		button1 = new JButton("Testa");

		button1.addActionListener( new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				Esercizio16.this.text.append("Testa\n");
			}
		});

		button2 = new JButton("Croce");

		button2.addActionListener( new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				Esercizio16.this.text.append("Croce\n");
			}
		});

		JPanel panel = new JPanel();
		panel.add(button1);
		panel.add(button2);

		this.setLayout(new BoxLayout(this.getContentPane(), BoxLayout.Y_AXIS));

		JScrollPane scroll = new JScrollPane(text);
		scroll.setPreferredSize(new Dimension(280, 220));

		this.getContentPane().add(scroll);
		this.getContentPane().add(panel);
		this.pack();
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setVisible(true);
	}

	public static void main(String [] args) {
		new Esercizio16();
	}
}

