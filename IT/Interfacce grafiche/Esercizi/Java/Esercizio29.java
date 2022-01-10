/* file Esercizio29.java */

import java.io.File;
import java.io.FileWriter;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.IOException;
import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.JComponent;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextArea;
import javax.swing.JMenuBar;
import javax.swing.JMenu;
import javax.swing.JMenuItem;
import javax.swing.JScrollPane;
import javax.swing.JOptionPane;
import javax.swing.JFileChooser;
import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Esercizio29 extends JFrame implements ActionListener {
	private String fileName;
	private JLabel label;
	private JTextArea textArea;

	public Esercizio29(String fileName) {
		this.fileName = fileName;

		JMenu fileMenu = new JMenu("File");

		JMenuItem newf = new JMenuItem("Nuovo");
		JMenuItem openf = new JMenuItem("Apri");
		JMenuItem svf = new JMenuItem("Salva");
		JMenuItem svfn = new JMenuItem("Salva con nome");
		JMenuItem exit = new JMenuItem("Esci");

		svf.putClientProperty("swn", false);
		svfn.putClientProperty("swn", true);

		svf.addActionListener(this);
		svfn.addActionListener(this);

		newf.addActionListener(   new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				Esercizio29.this.fileName = "";
				Esercizio29.this.label.setText("<nuovo>");
				Esercizio29.this.textArea.setText("");
			}
		});

		openf.addActionListener(   new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				JFileChooser fc = new JFileChooser();
				fc.setDialogTitle("Apri file: ");
				fc.setCurrentDirectory(new File(System.getProperty("user.dir")));
				if (fc.showOpenDialog(Esercizio29.this) != JFileChooser.APPROVE_OPTION) return;
				File doc = fc.getSelectedFile();
				String fname = doc.getName();
				Esercizio29.this.fileName = fname;
				Esercizio29.this.label.setText("\"" + fname + "\"");
				try {
					if (doc.exists()) {
						BufferedReader bufferedReader = new BufferedReader(new FileReader(doc));
						StringBuilder fullText = new StringBuilder();

						while (bufferedReader.ready()) {
							fullText.append(bufferedReader.readLine() + System.lineSeparator());
						}

						textArea.setText(fullText.toString());
					}
				}
				catch (FileNotFoundException ex) {
					System.err.println(ex);
				}
				catch (IOException ex) {
					System.err.println(ex);
				}
			}
		});

		exit.addActionListener(	new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				System.exit(0);
			}
		});

		JMenuBar menuBar = new JMenuBar();

		fileMenu.add(newf);
		fileMenu.add(openf);
		fileMenu.add(svf);
		fileMenu.add(svfn);
		fileMenu.add(exit);

		menuBar.add(fileMenu);
		this.setJMenuBar(menuBar);

		textArea = new JTextArea(25, 50);
		JScrollPane scroll = new JScrollPane(textArea);
		this.label = new JLabel("<nuovo>");

		Box box = new Box(BoxLayout.Y_AXIS);
		box.setAlignmentX(JComponent.CENTER_ALIGNMENT);
		box.add(Box.createVerticalGlue());
		box.add(label);

		this.getContentPane().setLayout(new BoxLayout(this.getContentPane(), BoxLayout.Y_AXIS));
		this.add(box);
		this.add(scroll);

		if (!this.fileName.isEmpty()) {
			try {
				File doc = new File(fileName);

				if (doc.exists()) {
					this.label.setText("\"" + this.fileName + "\"");
					BufferedReader bufferedReader = new BufferedReader(new FileReader(doc));
					StringBuilder fullText = new StringBuilder();

					while (bufferedReader.ready()) {
						fullText.append(bufferedReader.readLine() + System.lineSeparator());
					}

					textArea.setText(fullText.toString());
				}
				else {
					JOptionPane.showMessageDialog(this, "Il file " + fileName + " non esiste!", "Attenzione!", JOptionPane.WARNING_MESSAGE);
				}
			}
			catch (FileNotFoundException e) {
				System.err.println(e);
			}
			catch (IOException e) {
				System.err.println(e);
			}
		}

		this.setSize(new Dimension(640, 520));
		this.setTitle("ProgEdit");
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setVisible(true);
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		File doc = null;
		// salva con nome
		boolean swn = ((Boolean)((JMenuItem) e.getSource()).getClientProperty("swn"));
		if (this.fileName.isEmpty() || swn == true) {
			JFileChooser fc = new JFileChooser();
			fc.setCurrentDirectory(new File(System.getProperty("user.dir")));
			if (fc.showOpenDialog(this) != JFileChooser.APPROVE_OPTION) return;
			doc = fc.getSelectedFile();
			String fname = doc.getName();

			if (doc.exists()) {
				int resp = JOptionPane.showConfirmDialog(null, "Il file " + fname + " esiste già. Vuoi sovrascriverlo?", "Attenzione!", JOptionPane.YES_NO_OPTION, JOptionPane.QUESTION_MESSAGE);
				if (resp != JOptionPane.YES_OPTION) return;
			}

			this.fileName = fname;
			this.label.setText("\"" + this.fileName + "\"");
		}

		String fullText = textArea.getText();

		String [] lines = fullText.split(System.lineSeparator());

		try
		{
			if (doc == null) {
				doc = new File(this.fileName);
			}

			FileWriter docWriter = new FileWriter(doc);
			BufferedWriter bufferedWriter = new BufferedWriter(docWriter);

			for (String line : lines) {
				bufferedWriter.write(line + System.lineSeparator());
			}

			bufferedWriter.close();
		}
		catch (FileNotFoundException ex) {
			System.err.println(e);
		}
		catch (IOException ex) {
			System.err.println(e);
		}
	}

	public static void main(String [] args) {
		if (args.length > 0) {
			String fileName = args[0];
			new Esercizio29(fileName);
		}
		else {
			new Esercizio29("");
		}
	}
}

