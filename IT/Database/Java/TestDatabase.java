/*
file TestDatabase.java
eseguire con: java -cp .:sqlite-jdbc-<nnn>.jar TestDatabase
*/

import java.sql.DriverManager;
import java.sql.Connection;
import java.sql.Statement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class TestDatabase {
	public static void main(String [] args) {
		Connection conn = null;
		Statement stmt = null;
		ResultSet res = null;

		try {
			/* carica in memoria il driver necessario per connettersi al database SQLite */

			Class.forName("org.sqlite.JDBC");

			/* crea una connessione al database */

			conn = DriverManager.getConnection("jdbc:sqlite:test.db");

			/* crea uno Statement per interagire con il database */

			stmt = conn.createStatement();

			/* crea la nuova tabella degli attori */

			stmt.executeUpdate("CREATE TABLE IF NOT EXISTS actors (id INTEGER PRIMARY KEY, name VARCHAR NOT NULL, surname VARCHAR NOT NULL, CHECK(LENGTH(name) <= 256), CHECK(LENGTH(surname) <= 256))");

			/* svuota la tabella creata in precedenza: solo a scopo d'esempio! */

			stmt.executeUpdate("DELETE FROM actors");

			/* aggiunge tre righe alla tabella degli attori */

			stmt.executeUpdate("INSERT INTO actors (name, surname) VALUES ('Clark', 'Gable')"); 
			stmt.executeUpdate("INSERT INTO actors (name, surname) VALUES ('Cary', 'Grant')");
			stmt.executeUpdate("INSERT INTO actors (name, surname) VALUES ('Sean', 'Connery')");

			/* seleziona tutti gli attori */

			res = stmt.executeQuery("SELECT * FROM actors");

			/* finchè ci sono righe da stampare, stampa ciascuna colonna di ogni riga */

			while (res.next()) {
				int id = res.getInt("id");
				String name = res.getString("name");
				String surname = res.getString("surname");
				System.out.println(id + " " + name + " " + surname);
			}
		}
		catch (ClassNotFoundException e) {
			System.err.println(e);
		}
		catch (SQLException e) {
			System.err.println(e);
		}
		finally {
			/* chiude il ResultSet, lo statement e la connessione al database */
			try {
				if (res != null) res.close();
				if (stmt != null) stmt.close();
				if (conn != null) conn.close();
			}
			catch (SQLException e) {
				System.err.println(e);
			}
		}
	}
}

