/* file MainFrame.java */

package programmiamo.ind;

import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowEvent;
import java.awt.event.WindowAdapter;
import javax.swing.JFrame;
import javax.swing.JMenuBar;
import javax.swing.JMenu;
import javax.swing.JMenuItem;
import javax.swing.JTabbedPane;
import javax.swing.JPanel;
import java.sql.DriverManager;
import java.sql.Connection;
import java.sql.Statement;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class MainFrame extends JFrame {
	/* connessione al database */

	private Connection conn;
	private Statement stmt;
	private ResultSet res;
	private JTabbedPane tabs;

	public MainFrame() {
		/* crea il Notebook */

		tabs = new JTabbedPane();

		/* apre la connessione al database, soltanto la prima volta */

		try {
			Class.forName("org.sqlite.JDBC");
			conn = DriverManager.getConnection("jdbc:sqlite:addrb.db");
			stmt = conn.createStatement();

			/* se non esiste, crea la tabella dei contatti */

			stmt.executeUpdate("CREATE TABLE IF NOT EXISTS contacts (id INTEGER PRIMARY KEY, name VARCHAR, surname VARCHAR, addr VARCHAR, pnum VARCHAR, email VARCHAR, CHECK(LENGTH(pnum <= 15)))");

			updateUI();

		} catch (ClassNotFoundException e) {
			System.err.println(e);
		} catch (SQLException e) {
			System.err.println(e);
		}
		finally {
			try {
				if (res != null) res.close();
				if (stmt != null) stmt.close();
			}
			catch (SQLException e) {
				System.err.println(e);
			}
		}

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
				new NContact(MainFrame.this);
			}
		});

		/* gestisce il click sul menu "Cancella" */

		remove.addActionListener(	new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				int index = MainFrame.this.tabs.getSelectedIndex();
				Contact tab = (Contact)tabs.getComponentAt(index);

				String name = tab.name.getText();
				String surname = tab.surname.getText();
				PreparedStatement pStmt = null;

				try {
					pStmt = conn.prepareStatement("DELETE FROM contacts WHERE name = ? AND surname = ?");
					pStmt.setString(1, name);
					pStmt.setString(2, surname);
					pStmt.executeUpdate();
					updateUI();

				} catch (SQLException ex) {
					ex.printStackTrace();
				}
				finally {
					try {
						if (pStmt != null) pStmt.close();
					}
					catch (SQLException ex) {
						System.err.println(ex);
					}
				}
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
		this.addWindowListener(	new WindowAdapter() {
			@Override
			public void windowClosing(WindowEvent e) {
				// Alla chiusura della finestra principale, chiude il ResultSet, lo statement e la connessione al database
				try {
					if (res != null) res.close();
					if (stmt != null) stmt.close();
					if (conn != null) conn.close();
				}
				catch (SQLException ex) {
					System.err.println(ex);
				}
			}
		});
	}

	/* restituisce una connessione al database */

	public Connection getConnection() {
		return this.conn;
	}

	/* crea le linguette dei contatti nel Notebook */

	public void updateUI() throws SQLException {
		this.tabs.removeAll();

		stmt = conn.createStatement();
		res = stmt.executeQuery("SELECT name, surname, addr, pnum, email FROM contacts");

		while (res.next()) {
			/* recupera i dati del contatto dal database */
			String name = res.getString("name");
			String surname = res.getString("surname");
			String addr = res.getString("addr");
			String pnum = res.getString("pnum");
			String email = res.getString("email");

			Contact contact = new Contact(name, surname, addr, pnum, email);
			tabs.addTab(name + " " + surname, contact);
		}
	}
}

