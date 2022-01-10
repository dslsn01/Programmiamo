/*
file Esercizio11.java
eseguire con: java -cp .:sqlitejdbc-v<nnn>.jar Esercizio11
*/

import java.sql.DriverManager;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.Statement;
import java.sql.SQLException;

public class Esercizio11 {
	public static void main(String [] args) {
		Connection conn = null;
		Statement stmt = null;
		ResultSet res = null;

		try {
			Class.forName("org.sqlite.JDBC");
			String dbName = "students.db";
			conn = DriverManager.getConnection("jdbc:sqlite:" + dbName);
			stmt = conn.createStatement();

			res = stmt.executeQuery("SELECT MAX(grade) FROM students");

			int max = 0;

			if (res.next()) {
				max = res.getInt(1);
			}

			if (max == 0) {
				System.out.println("Nessuno studente ha ancora passato l'esame.");
				res.close();
				stmt.close();
				conn.close();
				return;
			}

			System.out.println("Voto massimo: " + max);
		}
		catch (ClassNotFoundException e) {
			System.err.println(e);
		}
		catch (SQLException e) {
			System.err.println(e);
		}
		finally {
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

