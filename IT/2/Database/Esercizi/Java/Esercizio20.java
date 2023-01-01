/*
file Esercizio20.java
eseguire con: java -cp .:sqlitejdbc-v<nnn>.jar Esercizio20
*/

import java.io.Console;
import java.util.Map;
import java.util.LinkedHashMap;
import java.util.Map.Entry;
import java.sql.DriverManager;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class Esercizio20 {
	public static void main(String [] args) {
		System.out.println("Cerca un film per titolo, anno, regista e attore principale.");

		Connection conn = null;
		PreparedStatement pStmt = null;
		ResultSet res = null;

		try {
			Class.forName("org.sqlite.JDBC");
			String dbName = "videostore.db";
			conn = DriverManager.getConnection("jdbc:sqlite:" + dbName);
			String query = "SELECT title, year, director, star FROM movies";
			Map<String, String> params = new LinkedHashMap<>();

			Console console = System.console();

			String title = console.readLine("Titolo del film: ");

			if (!title.isEmpty()) {
				params.put("title", title);
			}

			String year = console.readLine("Anno: ");

			if (!year.isEmpty()) {
				params.put("year", year);
			}

			String director = console.readLine("Regista: ");

			if (!director.isEmpty()) {
				params.put("director", director);
			}

			String star = console.readLine("Attore principale: ");

			if (!star.isEmpty()) {
				params.put("star", star);
			}

			if (params.size() != 0) {
				int i = 0;
				for (String k : params.keySet()) {
					String clause = (i == 0) ? " WHERE " + k + " = ?" : " AND " + k + " = ?";
					query += clause;
					i++;
				}

				pStmt = conn.prepareStatement(query);

				int j = 1;
				for (String value : params.values()) {
					pStmt.setString(j, value);
					j++;
				}
			}
			else {
				// senza parametri posizionali
				pStmt = conn.prepareStatement(query);
			}

			res = pStmt.executeQuery();

			if (!res.isBeforeFirst()) {
				System.out.println("Film non disponibile in videoteca!");
				pStmt.close();
				conn.close();
			}

			while (res.next()) {
				StringBuilder sb = new StringBuilder();
				sb.append(res.getString(1));
				int yr = res.getInt(2);
				if (yr != 0) sb.append(" (" + yr + ")");
				sb.append(", regista: " + res.getString(3));
				String pr = res.getString(4);
				if (!star.isEmpty()) {
					sb.append(", attore principale: " + pr);
				}
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
				if (pStmt != null) pStmt.close();
				if (conn != null) conn.close();
			}
			catch (SQLException e) {
				System.err.println(e);
			}
		}
	}
}

