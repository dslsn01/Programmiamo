/*
file Esercizio27.java
eseguire con: java -cp .:sqlitejdbc-v<nnn>.jar Esercizio27
*/

import java.io.Console;
import java.sql.DriverManager;
import java.sql.Connection;
import java.sql.Statement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class Esercizio27 {
	public static void main(String [] args) {
		Connection conn = null;
		Statement stmt = null;

		try {
			Class.forName("org.sqlite.JDBC");
			String dbName = "bank.db";
			conn = DriverManager.getConnection("jdbc:sqlite:" + dbName);
			stmt = conn.createStatement();

			/* tabella dei conti deposito che si appoggiano ai conti correnti. */

			conn.setAutoCommit(false);

			stmt.addBatch("PRAGMA foreign_keys = ON;");
			stmt.addBatch("CREATE TABLE deposit (cc VARCHAR, bal REAL, FOREIGN KEY(cc) REFERENCES customers(n_acc));");

			stmt.executeBatch();
			conn.commit();
			conn.setAutoCommit(true);

			System.out.println("Creata tabella dei depositi.");
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

