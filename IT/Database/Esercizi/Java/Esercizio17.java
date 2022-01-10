/*
file Esercizio17.java
eseguire con: java -cp .:sqlitejdbc-v<nnn>.jar Esercizio17
*/

import java.io.Console;
import java.sql.DriverManager;
import java.sql.Connection;
import java.sql.Statement;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class Esercizio17 {
	public static void main(String [] args) {
		Connection conn = null;
		Statement stmt = null;
		PreparedStatement pStmt = null;
		int [] records = {};

		try {
			Class.forName("org.sqlite.JDBC");
			String dbName = "videostore.db";
			conn = DriverManager.getConnection("jdbc:sqlite:" + dbName);
			stmt = conn.createStatement();

			stmt.executeUpdate("CREATE TABLE IF NOT EXISTS movies (id INTEGER PRIMARY KEY, title VARCHAR UNIQUE NOT NULL, year INTEGER, CHECK(LENGTH(title) <= 255), CHECK(LENGTH(year) == 4))");

			pStmt = conn.prepareStatement("INSERT INTO movies (title, year) VALUES (?, ?)");

			System.out.println("Film da salvare (stringa vuota per uscire).");
			Console console = System.console();

			while (true) {
				String title = console.readLine("Titolo film: ");

				if (title.isEmpty()) break;

				String year = console.readLine("Anno: ");

				int yr = 0;

				try {
					if (!year.isEmpty()) yr = Integer.parseInt(year);
				}
				catch (NumberFormatException e) {
					System.out.println(e);
				}

				pStmt.setString(1, title);

				if (yr != 0) {
					pStmt.setInt(2, yr);
				}
				else {
					pStmt.setNull(2, java.sql.Types.INTEGER);
				}

				pStmt.addBatch();
			}

			records = pStmt.executeBatch();

			int tot = 0;
			for (int record : records) {
				tot += record;
			}

			System.out.println("Registrati " + tot + " film.");
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
				if (pStmt != null) pStmt.close();
				if (conn != null) conn.close();
			}
			catch (SQLException e) {
				System.err.println(e);
			}
		}
	}
}

