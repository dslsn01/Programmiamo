/*
file Esercizio18.java
eseguire con: java -cp .:sqlitejdbc-v<nnn>.jar Esercizio18
*/

import java.sql.DriverManager;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.Statement;
import java.sql.SQLException;

public class Esercizio18 {
	public static void main(String [] args) {
		Connection conn = null;
		Statement stmt = null;
		ResultSet res = null;

		try {
			Class.forName("org.sqlite.JDBC");
			String dbName = "videostore.db";
			conn = DriverManager.getConnection("jdbc:sqlite:" + dbName);
			stmt = conn.createStatement();

			res = stmt.executeQuery("SELECT title, year FROM movies");

			if (!res.isBeforeFirst()) {
				System.out.println("Nessun film disponibile in videoteca!");
				res.close();
				stmt.close();
				conn.close();
				return;
			}

			while (res.next()) {
				StringBuilder sb = new StringBuilder();
				sb.append(res.getString(1));
				int yr = res.getInt(2);
				if (yr != 0) sb.append(" (" + yr + ")");
				sb.append(".");
				System.out.println(sb.toString());
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

