/*
file Esercizio6.java
eseguire con: java -cp .:sqlitejdbc-v<nnn>.jar Esercizio6
*/

import java.sql.DriverManager;
import java.sql.Connection;
import java.sql.Statement;
import java.sql.SQLException;

public class Esercizio6 {
	public static void main(String [] args) {
		Connection conn = null;
		Statement stmt = null;

		try {
			Class.forName("org.sqlite.JDBC");
			String dbName = "students.db";
			conn = DriverManager.getConnection("jdbc:sqlite:" + dbName);
			stmt = conn.createStatement();

			stmt.executeUpdate("CREATE TABLE students (id INTEGER PRIMARY KEY, number VARCHAR UNIQUE NOT NULL, name VARCHAR NOT NULL, surname VARCHAR NOT NULL, age INTEGER, CHECK(LENGTH(number) == 6), CHECK(LENGTH(name) <= 255), CHECK(LENGTH(surname) <= 255))");

			System.out.println("Creata tabella degli studenti.");
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

