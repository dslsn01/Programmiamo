/*
file Esercizio9.java
eseguire con: java -cp .:sqlitejdbc-v<nnn>.jar Esercizio9
*/

import java.io.Console;
import java.sql.DriverManager;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.Statement;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class Esercizio9 {
	public static void main(String [] args) {
		System.out.println("Aggiorna il voto d'esame degli studenti.");

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

			if (!res.isBeforeFirst()) {
				System.out.println("Non ci sono studenti iscritti al corso!");
				res.close();
				stmt.close();
				conn.close();
				return;
			}

			pStmt = conn.prepareStatement("UPDATE students SET grade = ? WHERE number = ?");
			Console console = System.console();

			while (res.next()) {
				String num = res.getString(1);
				System.out.println("Matricola " + num + ", " + res.getString(2) + " " + res.getString(3));

				String s = console.readLine("Voto (da 18 a 30): ");
				if (s.isEmpty()) continue;
				int grade = 0;

				try {
					grade = Integer.parseInt(s);
					if (grade < 18 || grade > 30) {
						System.err.println("Voto non valido!");
						continue;
					}
				}
				catch (NumberFormatException e) {
					System.err.println(e);
					continue;
				}

				pStmt.setInt(1, grade);
				pStmt.setString(2, num);
				pStmt.addBatch();
				// pStmt.clearParameters();
			}

			records = pStmt.executeBatch();
			// pStmt.clearBatch();
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
		for (int record : records) tot += record;

		System.out.println(tot + " studenti hanno passato la prova d'esame.");
	}
}

