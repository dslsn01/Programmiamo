/*
file Esercizio14.java
eseguire con: java -cp .:sqlitejdbc-v<nnn>.jar Esercizio14
*/

import java.sql.DriverManager;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.Statement;
import java.sql.SQLException;

public class Esercizio14 {
	public static void main(String [] args) {
		Connection conn = null;
		Statement stmt = null;
		ResultSet res = null;

		try {
			Class.forName("org.sqlite.JDBC");
			String dbName = "students.db";
			conn = DriverManager.getConnection("jdbc:sqlite:" + dbName);

			String query = "SELECT a.number, a.name, a.surname, a.grade ";
			query += "FROM students a ";
			query += "INNER JOIN (";
			query += "SELECT MAX(grade) AS grade FROM students";
			query += ") b ON a.grade = b.grade";

			stmt = conn.createStatement();
			res = stmt.executeQuery(query);

			if (!res.isBeforeFirst()) {
				System.out.println("Nessuno studente ha ancora passato l'esame.");
				res.close();
				stmt.close();
				conn.close();
				return;
			}

			while (res.next()) {
				System.out.println("Matricola " + res.getString(1) + ", " + res.getString(2) + " " + res.getString(3) + ", voto: " + res.getInt(4));
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

