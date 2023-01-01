/*
file Esercizio8.java
eseguire con: java -cp .:sqlitejdbc-v<nnn>.jar Esercizio8
*/

import java.io.Console;
import java.sql.DriverManager;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class Esercizio8 {
	public static void main(String [] args) {
		System.out.println("Inserisci gli studenti del corso (matricola vuota per uscire).");

		Connection conn = null;
		PreparedStatement pStmt = null;
		int [] records = {};

		try {
			Class.forName("org.sqlite.JDBC");
			String dbName = "students.db";
			conn = DriverManager.getConnection("jdbc:sqlite:" + dbName);

			pStmt = conn.prepareStatement("INSERT INTO students (number, name, surname, age, grade) VALUES (?, ?, ?, ?, ?)");
			Console console = System.console();

			while (true) {
				try {
					String num = console.readLine("Numero di matricola: ");

					if (num.isEmpty()) break;

					String name = console.readLine("Nome: ");
					String surname = console.readLine("Cognome: ");
					String s1 = console.readLine("Anni: ");
					int age = 0;

					if (!s1.isEmpty()) {
						age = Integer.parseInt(s1);
					}

					String s2 = console.readLine("Voto: ");
					int grade = 0;

					if (!s2.isEmpty()) {
						grade = Integer.parseInt(s2);
					}

					pStmt.setString(1, num);

					if (!name.isEmpty()) {
						pStmt.setString(2, name);
					}
					else {
						pStmt.setNull(2, java.sql.Types.VARCHAR);
					}

					if (!surname.isEmpty()) {
						pStmt.setString(3, surname);
					}
					else {
						pStmt.setNull(3, java.sql.Types.VARCHAR);
					}

					if (age != 0) {
						pStmt.setInt(4, age);
					}
					else {
						pStmt.setNull(4, java.sql.Types.INTEGER);
					}

					if (grade != 0) {
						pStmt.setInt(5, grade);
					}
					else {
						pStmt.setNull(5, java.sql.Types.INTEGER);
					}

					pStmt.addBatch();
				}
				catch (NumberFormatException e) {
					System.err.println(e);
				}
				catch (SQLException e) {
					System.err.println(e);
				}
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

		System.out.println("Registrati " + tot + " studenti.");
	}
}

