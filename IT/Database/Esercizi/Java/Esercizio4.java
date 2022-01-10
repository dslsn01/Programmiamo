/*
file Esercizio4.java
eseguire con: java -cp .:sqlitejdbc-v<nnn>.jar Esercizio4
*/

import java.sql.DriverManager;
import java.sql.Connection;
import java.sql.Statement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class Esercizio4 {
	public static void main(String [] args) {
		Connection conn = null;
		Statement stmt = null;

		try {
			Class.forName("org.sqlite.JDBC");
			String dbName = "students.db";
			conn = DriverManager.getConnection("jdbc:sqlite:" + dbName);
			stmt = conn.createStatement();

			stmt.executeUpdate("DELETE FROM students");

			System.out.println("Tabella degli studenti svuotata.");
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

