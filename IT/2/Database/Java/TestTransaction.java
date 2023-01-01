/*
file TestTransaction.java
compilare con: javac -cp .:sqlite-jdbc-<nnn>.jar TestTransaction.java
eseguire con:  java -cp .:sqlite-jdbc-<nnn>.jar TestTransaction
*/

import java.sql.DriverManager;
import java.sql.Connection;
import java.sql.Statement;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.text.SimpleDateFormat;
import java.text.ParseException;
import java.util.Calendar;
import java.util.Date;
import org.sqlite.SQLiteConfig;

public class TestTransaction {
	public static void main(String [] args) {
		Connection conn = null;
		Statement stmt = null;
		PreparedStatement pStmt = null;
		ResultSet res = null;

		try {
			Class.forName("org.sqlite.JDBC");
			SQLiteConfig cfg = new SQLiteConfig();
			// abilita le foreign key
			cfg.enforceForeignKeys(true);
			conn = DriverManager.getConnection("jdbc:sqlite:list.db", cfg.toProperties());
			stmt = conn.createStatement();

			// inizio prima transazione
			conn.setAutoCommit(false);

			// crea tabella dei pazienti, lista d'attesa e degli interventi programmati

			stmt.addBatch("CREATE TABLE IF NOT EXISTS patients (name VARCHAR NOT NULL, surname VARCHAR NOT NULL, PRIMARY KEY(name, surname), CHECK(LENGTH(name) <= 256), CHECK(LENGTH(surname) <= 256))");
			stmt.addBatch("CREATE TABLE IF NOT EXISTS wtList (name VARCHAR, surname VARCHAR, r_date DATE NOT NULL, FOREIGN KEY(name, surname) REFERENCES patients(name, surname) ON DELETE CASCADE)");
			stmt.addBatch("CREATE TABLE IF NOT EXISTS interv (name VARCHAR, surname VARCHAR, sched DATE NOT NULL, desc VARCHAR, CHECK(LENGTH(desc) <= 256), FOREIGN KEY(name, surname) REFERENCES patients(name, surname) ON DELETE CASCADE)");

			// svuota tutt'e tre le tabelle (solo a scopo di test!)

			stmt.addBatch("DELETE FROM patients");
			stmt.addBatch("DELETE FROM wtList");
			stmt.addBatch("DELETE FROM interv");

			// salva i nominativi di tre pazienti

			stmt.addBatch("INSERT INTO patients (name, surname) VALUES ('Giovanni', 'Verdi')");
			stmt.addBatch("INSERT INTO patients (name, surname) VALUES ('Giuseppe', 'Bianchi')");
			stmt.addBatch("INSERT INTO patients (name, surname) VALUES ('Luigi', 'Rossi')");

			// inserisce due pazienti in lista d'attesa in modo casuale

			stmt.addBatch("INSERT INTO wtList (name, surname, r_date) SELECT name, surname, DATE('now') FROM patients ORDER BY RANDOM() LIMIT 2");

			// esegue i comandi SQL in sequenza
			stmt.executeBatch();

			// fine prima transazione
			conn.commit();
			conn.setAutoCommit(true);

			String name = null;
			String surname = null;
			Date r_date = null;
			SimpleDateFormat fmt1 = new SimpleDateFormat("yyyy-MM-dd");
			SimpleDateFormat fmt2 = new SimpleDateFormat("dd/MM/yyyy");

			res = stmt.executeQuery("SELECT name, surname, r_date FROM wtList LIMIT 1");

			if (res.next()) {
				try {
					name = res.getString(1);
					surname = res.getString(2);
					r_date = fmt1.parse(res.getString(3));
					System.out.println("Il paziente " + name + " " + surname + " è in lista d'attesa dal " + fmt2.format(r_date) + ".");
				}
				catch (ParseException e) {
					System.err.println(e);
				}
			}

			res.close();

			// inizio seconda transazione
			conn.setAutoCommit(false);

			// inserisce un paziente nella lista degli interventi programmati, rimuovendolo dalla lista d'attesa
			pStmt = conn.prepareStatement("INSERT INTO interv (name, surname, sched, desc) VALUES (?, ?, ?, ?)");
			pStmt.setString(1, name);
			pStmt.setString(2, surname);

			Calendar cal = Calendar.getInstance();
			cal.setTime(r_date);
			cal.add(Calendar.DATE, 3);
			Date i_date = cal.getTime();
			String dt = fmt1.format(i_date);

			pStmt.setString(3, dt);
			pStmt.setString(4, "endodonzia");
			pStmt.executeUpdate();
			pStmt.close();

			pStmt = conn.prepareStatement("DELETE FROM wtList WHERE name = ? AND surname = ?");
			pStmt.setString(1, name);
			pStmt.setString(2, surname);
			pStmt.executeUpdate();
			pStmt.close();

			// fine seconda transazione
			conn.commit();
			conn.setAutoCommit(true);

			System.out.println(name + " " + surname + " sarà sottoposto a intervento il giorno " + fmt2.format(i_date) + ".");
		}
		catch (ClassNotFoundException e) {
			System.err.println(e);
		}
		catch (SQLException e) {
			System.err.println(e);
		}
		finally {
			/* chiude esplicitamente tutte le risorse */
			try {
				if (res != null) res.close();
				if (pStmt != null) pStmt.close();
				if (stmt != null) stmt.close();
				if (conn != null) conn.close();
			}
			catch (SQLException e) {
				System.err.println(e);
			}
		}
	}
}

