/*
file Esercizio2.java
eseguire con: java -cp .:sqlitejdbc-v<nnn>.jar Esercizio2
*/

import java.sql.DriverManager;
import java.sql.Connection;
import java.sql.Statement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class Esercizio2 {
	public static void main(String [] args) {
		Connection conn = null;
		Statement stmt = null;
		ResultSet test = null;

		try {
			Class.forName("org.sqlite.JDBC");
			String dbName = "students.db";
			conn = DriverManager.getConnection("jdbc:sqlite:" + dbName);
			stmt = conn.createStatement();

			test = stmt.executeQuery("SELECT COUNT(*) FROM students");

			test.next();
			int count = test.getInt(1);

			if (count != 0) {
				System.out.println("Tabella degli studenti non vuota!");
				test.close();
				stmt.close();
				conn.close();
				return;
			}

			stmt.executeUpdate("INSERT INTO students (number, name, surname, age) VALUES ('A23234', 'Mario', 'Rossi', 19)");
			stmt.executeUpdate("INSERT INTO students (number, name, surname, age) VALUES ('A01357', 'Luigi', 'Bianchi', 20)");
			stmt.executeUpdate("INSERT INTO students (number, name, surname, age) VALUES ('A12579', 'Giovanni', 'Verdi', 20)");

			System.out.println("Tre nuovi studenti iscritti al corso.");
		}
		catch (ClassNotFoundException e) {
			System.err.println(e);
		}
		catch (SQLException e) {
			System.err.println(e);
		}
		finally {
			try {
				if (test != null) test.close();
				if (stmt != null) stmt.close();
				if (conn != null) conn.close();
			}
			catch (SQLException e) {
				System.err.println(e);
			}
		}
	}
}

