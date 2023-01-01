/*
file Esercizio24.java
eseguire con: java -cp .:sqlitejdbc-v<nnn>.jar Esercizio24
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

public class Esercizio24 {
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

			stmt.executeUpdate("CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY, username VARCHAR UNIQUE NOT NULL, password VARCHAR NOT NULL, name VARCHAR NOT NULL, surname VARCHAR NOT NULL, r_date DATE, llogin TIMESTAMP, CHECK(LENGTH(username) <= 50), CHECK(LENGTH(password) <= 50))");

			// nome, data di registrazione e ultimo login
			String name = "";
			SimpleDateFormat fmt = new SimpleDateFormat("yyyy-MM-dd");
			String r_date = "";
			String llogin = "";

			System.out.println("##################################");
			System.out.println("####### Schermata di login #######");
			System.out.println("##################################");

			String username = console.readLine("Username: ").toLowerCase();

			pStmt = conn.prepareStatement("SELECT name, surname, password, r_date, llogin FROM users WHERE username = ?");
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

				pStmt = conn.prepareStatement("INSERT INTO users (username, password, name, surname, r_date, llogin) VALUES (?, ?, ?, ?, ?, ?)");

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

				Date dt = new Date();
				r_date = fmt.format(dt);
				llogin = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss").format(dt);

				pStmt.setString(5, r_date);
				pStmt.setString(6, llogin);
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
					pStmt = conn.prepareStatement("UPDATE users SET llogin = ? WHERE username = ?");
					String dt = new SimpleDateFormat("dd-MM-yyyy HH:mm:ss").format(new Date());
					pStmt.setString(1, dt);
					pStmt.setString(2, username);
					pStmt.executeUpdate();
					pStmt.close();
				}

				name = res.getString(1);
				r_date = res.getString(4);
				// data ultimo accesso
				llogin = res.getString(5);

				res.close();
			}

			try {
				r_date = new SimpleDateFormat("dd/MM/yyyy").format(fmt.parse(r_date));
				SimpleDateFormat f2 = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
				llogin = new SimpleDateFormat("dd/MM/yyyy HH:mm:ss").format(f2.parse(llogin));
			}
			catch (ParseException e) {
				System.err.println(e);
			}

			System.out.println("++++++++++++++++++++++++++++++++++");
			System.out.println("Benvenuto, " + name + "!" + System.lineSeparator() + "Sei registrato dal " + r_date + "." + System.lineSeparator() + "Ultimo accesso effettuato il " + llogin + ".");
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

