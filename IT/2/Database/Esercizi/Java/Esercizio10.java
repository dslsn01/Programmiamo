/*
file Esercizio10.java
eseguire con: java -cp .:sqlitejdbc-v<nnn>.jar Esercizio10
*/

import java.io.Console;
import java.sql.DriverManager;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.Statement;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class Esercizio10 {
	public static void main(String [] args) {
		System.out.println("Elimina uno o più studenti.");

		Connection conn = null;
		Statement stmt = null;
		PreparedStatement pStmt = null;
		ResultSet res = null;
		int [] records = {};

		try {
			Class.forName("org.sqlite.JDBC");
			String dbName = "students.db";
			conn = DriverManager.getConnection("jdbc:sqlite:" + dbName);
			stmt = conn.createStatement();

			res = stmt.executeQuery("SELECT number, name, surname FROM students");

			pStmt = conn.prepareStatement("DELETE FROM students WHERE number = ?");
			Console console = System.console();

			while (res.next()) {
				String num = res.getString(1);
				System.out.println("Matricola " + num + ", " + res.getString(2) + " " + res.getString(3));

				String opt = console.readLine("Rimuovere lo studente dal corso? ");
				if (!opt.equals("s")) continue;

				pStmt.setString(1, num);
				pStmt.addBatch();
			}

			records = pStmt.executeBatch();
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
				if (pStmt != null) pStmt.close();
				if (conn != null) conn.close();
			}
			catch (SQLException e) {
				System.err.println(e);
			}
		}

		int tot = 0;
		for (int record : records) {
			tot += record;
		}

		System.out.println("Eliminati " + tot + " record di studenti.");
	}
}

