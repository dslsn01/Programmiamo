/*
file Esercizio16.java
eseguire con: java -cp .:sqlitejdbc-v<nnn>.jar Esercizio16
*/

import java.sql.DriverManager;
import java.sql.Connection;
import java.sql.Statement;
import java.sql.SQLException;

public class Esercizio16 {
	public static void main(String [] args) {
		Connection conn = null;
		Statement stmt = null;

		try {
			Class.forName("org.sqlite.JDBC");
			String dbName = "students.db";
			conn = DriverManager.getConnection("jdbc:sqlite:" + dbName);
			stmt = conn.createStatement();

			stmt.executeUpdate("DELETE FROM students WHERE grade IS NOT NULL");

			System.out.println("Rimossi studenti che hanno superato l'esame.");
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

