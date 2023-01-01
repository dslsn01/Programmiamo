/* file Esercizio14.java */

import javax.swing.JFrame;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Esercizio14 {
	private JFrame frame;
	private JButton button;

	public Esercizio14() {
		frame = new JFrame();
		button = new JButton("Aiuto");

		button.addActionListener(   new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				JOptionPane.showMessageDialog(frame, "Hai chiesto aiuto!", "Alert", JOptionPane.INFORMATION_MESSAGE);
			}
		});

		frame.add(button);

		frame.pack();
		frame.setLocationRelativeTo(null);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
	}

	public static void main(String [] args) {
		new Esercizio14();
	}
}

