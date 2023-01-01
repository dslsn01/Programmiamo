/*
file Esercizio25.java
eseguire con: java -cp .:sqlitejdbc-v<nnn>.jar Esercizio25
*/

import java.io.Console;
import java.sql.DriverManager;
import java.sql.Connection;
import java.sql.Statement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class Esercizio25 {
	public static void main(String [] args) {
		Connection conn = null;
		Statement stmt = null;

		try {
			Class.forName("org.sqlite.JDBC");
			String dbName = "bank.db";
			conn = DriverManager.getConnection("jdbc:sqlite:" + dbName);
			stmt = conn.createStatement();

			/* tabella clienti: codice utente e password (almeno 8 cifre), numero conto (12 cifre), iban (27 cifre in italia) e saldo conto
			tabella movimenti: intestatario del conto, importo, casuale/descrizione, data valuta, data operativa. */

			conn.setAutoCommit(false);

			stmt.addBatch("PRAGMA foreign_keys = ON;");
			stmt.addBatch("CREATE TABLE customers (n_acc VARCHAR PRIMARY KEY, iban VARCHAR UNIQUE NOT NULL, ucode INTEGER NOT NULL, password VARCHAR NOT NULL, ident VARCHAR, bal REAL, CHECK(LENGTH(n_acc) == 12), CHECK(LENGTH(ucode) == 8), CHECK(LENGTH(password) == 8), CHECK(LENGTH(iban) == 27));");
			// ord iban ordinante, ben iban beneficiario
			stmt.addBatch("CREATE TABLE mov (id INTEGER PRIMARY KEY, ord VARCHAR, ben VARCHAR, imp REAL, desc VARCHAR, v_date TIMESTAMP, o_date TIMESTAMP, FOREIGN KEY(ord) REFERENCES customers(iban), FOREIGN KEY(ben) REFERENCES customers(iban));");

			stmt.executeBatch();
			// esegue il commit della transazione
			conn.commit();
			conn.setAutoCommit(true);

			System.out.println("Create le tabelle di clienti e movimenti.");

			// inserisce tre clienti di prova
			stmt.executeUpdate("INSERT INTO customers (n_acc, iban, ucode, password, ident, bal) VALUES ('000009753468', 'IT02S0300203280881249519873', 75310246, 'foobarba', 'Mario Rossi', 1000);");
			stmt.executeUpdate("INSERT INTO customers (n_acc, iban, ucode, password, ident, bal) VALUES ('000007986541', 'IT96W0300203280997548569793', 21304152, 'barbazfo', 'Luigi Bianchi', 1500);");
			stmt.executeUpdate("INSERT INTO customers (n_acc, iban, ucode, password, ident, bal) VALUES ('000001753429', 'IT80H0300203280392486464466', 30415263, 'bazfooba', 'Giovanni Verdi', 2500);");
			stmt.executeUpdate("INSERT INTO customers (n_acc, iban, ucode, password, ident, bal) VALUES ('000009078653', 'IT97E0300203280833549251697', 16180339, '1,7O9975', 'Fondo di investimento', 10000000);");
			stmt.close();

			System.out.println("La banca ha quattro nuovi clienti!");
		}
		catch (ClassNotFoundException e) {
			System.err.println(e);
		}
		catch (SQLException e) {
			System.err.println(e);
		}
		finally {
			try {
				if (stmt != null) stmt.close();
				if (conn != null) conn.close();
			}
			catch (SQLException e) {
				System.err.println(e);
			}
		}
	}
}

