/*
file Esercizio3.java
eseguire con: java -cp .:sqlitejdbc-v<nnn>.jar Esercizio3
*/

import java.sql.DriverManager;
import java.sql.Connection;
import java.sql.Statement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class Esercizio3 {
	public static void main(String [] args) {
		Connection conn = null;
		Statement stmt = null;
		ResultSet res = null;

		try {
			Class.forName("org.sqlite.JDBC");
			String dbName = "students.db";
			conn = DriverManager.getConnection("jdbc:sqlite:" + dbName);
			stmt = conn.createStatement();

			res = stmt.executeQuery("SELECT number, name, surname FROM students");

			if (!res.isBeforeFirst()) {
				System.out.println("Non ci sono studenti iscritti al corso!");
				res.close();
				stmt.close();
				conn.close();
				return;
			}

			while (res.next()) {
				String number = res.getString("number");
				String name = res.getString("name");
				String surname = res.getString("surname");
				System.out.println("Matricola " + number + ", " + name + " " + surname + ".");
			}
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

