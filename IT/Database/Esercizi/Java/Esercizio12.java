/*
file Esercizio12.java
eseguire con: java -cp .:sqlitejdbc-v<nnn>.jar Esercizio12
*/

import java.sql.DriverManager;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.Statement;
import java.sql.SQLException;

public class Esercizio12 {
	public static void main(String [] args) {
		Connection conn = null;
		Statement stmt = null;
		ResultSet res = null;

		try {
			Class.forName("org.sqlite.JDBC");
			String dbName = "students.db";
			conn = DriverManager.getConnection("jdbc:sqlite:" + dbName);
			stmt = conn.createStatement();

			res = stmt.executeQuery("SELECT MIN(grade) FROM students");

			int min = 0;

			if (res.next()) {
				min = res.getInt(1);
			}

			if (min == 0) {
				System.out.println("Nessuno studente ha ancora passato l'esame.");
				res.close();
				stmt.close();
				conn.close();
				return;
			}

			System.out.println("Voto minimo: " + min);
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

