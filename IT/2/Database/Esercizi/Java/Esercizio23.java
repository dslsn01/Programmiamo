/*
file Esercizio23.java
eseguire con: java -cp .:sqlitejdbc-v<nnn>.jar Esercizio23
*/

import java.io.Console;
import java.sql.DriverManager;
import java.sql.Connection;
import java.sql.Statement;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.text.SimpleDateFormat;
import java.text.ParseException;
import java.util.Date;

public class Esercizio23 {
	public static void main(String [] args) {
		Connection conn = null;
		Statement stmt = null;
		PreparedStatement pStmt = null;
		Console console = System.console();

		try {
			Class.forName("org.sqlite.JDBC");
			String dbName = "users.db";
			conn = DriverManager.getConnection("jdbc:sqlite:" + dbName);
			stmt = conn.createStatement();

			stmt.executeUpdate("CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY, username VARCHAR UNIQUE NOT NULL, password VARCHAR NOT NULL, name VARCHAR NOT NULL, surname VARCHAR NOT NULL, r_date DATE, CHECK(LENGTH(username) <= 50), CHECK(LENGTH(password) <= 50))");

			// nome e data di registrazione
			String name = "";
			SimpleDateFormat fmt = new SimpleDateFormat("yyyy-MM-dd");
			String r_date = "";

			System.out.println("##################################");
			System.out.println("####### Schermata di login #######");
			System.out.println("##################################");

			String username = console.readLine("Username: ").toLowerCase();

			pStmt = conn.prepareStatement("SELECT name, surname, password, r_date FROM users WHERE username = ?");
			pStmt.setString(1, username);
			ResultSet res = pStmt.executeQuery();

			if (!res.isBeforeFirst()) {
				res.close();
				pStmt.close();
				String opt = console.readLine("Username \"" + username + "\" non presente! Vuoi registrarti? s | n: ").toLowerCase();

				if (!opt.equals("s")) return;

				String pwd = console.readLine("Password: ");
				name = console.readLine("Nome: ");
				String surname = console.readLine("Cognome: ");

				pStmt = conn.prepareStatement("INSERT INTO users (username, password, name, surname, r_date) VALUES (?, ?, ?, ?, ?)");

				pStmt.setString(1, username);

				if (!pwd.isEmpty()) {
					pStmt.setString(2, pwd);
				}
				else {
					pStmt.setNull(2, java.sql.Types.VARCHAR);
				}

				if (!name.isEmpty()) {
					pStmt.setString(3, name);
				}
				else {
					pStmt.setNull(3, java.sql.Types.VARCHAR);
				}

				if (!surname.isEmpty()) {
					pStmt.setString(4, surname);
				}
				else {
					pStmt.setNull(4, java.sql.Types.VARCHAR);
				}

				r_date = fmt.format(new Date());

				pStmt.setString(5, r_date);
				pStmt.executeUpdate();
				pStmt.close();
			}
			else {
				boolean auth = false;
				int i = 0; // numero tentativi di autenticazione
				String _pwd = res.getString(3);
				while (!auth) {
					String pwd = console.readLine("Password: ");
					if (!pwd.equals(_pwd)) {
						i++;
						System.err.println("Password non corretta!");
						if (i < 3) continue;
						else {
							System.err.println("Tre tentativi di autenticazione fallita: stop.");
							return;
						}
					}

					auth = true;
				}

				name = res.getString(1);
				r_date = res.getString(4);

				res.close();
			}

			try {
				r_date = new SimpleDateFormat("dd/MM/yyyy").format(fmt.parse(r_date));
			}
			catch (ParseException e) {
				System.err.println(e);
			}

			System.out.println("++++++++++++++++++++++++++++++++++");
			System.out.println("Benvenuto, " + name + "!" + System.lineSeparator() + "Sei registrato dal " + r_date + ".");
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

