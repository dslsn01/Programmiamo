/*
file Esercizio30.java
eseguire con: java -cp .:sqlitejdbc-v<nnn>.jar Esercizio30
*/

import java.io.Console;
import java.math.BigDecimal;
import java.sql.DriverManager;
import java.sql.Connection;
import java.sql.Statement;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.text.SimpleDateFormat;
import java.util.Date;

public class Esercizio30 {
	private static boolean listOrd(Connection conn, String username) throws SQLException {
		boolean rc = false;
		PreparedStatement pStmt = conn.prepareStatement("SELECT o.id, o.product, p.price FROM orders o, products p WHERE user = ? AND o.product = p.name AND o.paid = 0");
		pStmt.setString(1, username);
		ResultSet res = pStmt.executeQuery();

		if (!res.isBeforeFirst()) {
			System.out.println("[X] Nessun ordine presente.");
		}
		else {
			rc = true;
			while (res.next()) {
				int id = res.getInt(1);
				String p = res.getString(2);
				String pr = res.getString(3);
				System.out.println("[" + id + "] " + p + " - " + pr + " euro.");
			}
		}

		res.close();
		pStmt.close();

		return rc;
	}

	private static void catalog(Connection conn) throws SQLException {
		ResultSet res = conn.createStatement().executeQuery("SELECT name, price FROM products");
		while (res.next()) {
			System.out.println(res.getString(1) + " - " + res.getBigDecimal(2) + " euro.");
		}
		res.close();
	}

	private static void summary(Connection conn, String username) throws SQLException {
		// ordini (da pagare)
		System.out.println("---------------------\nI tuoi ordini:\n");
		listOrd(conn, username);

		// acquisti passati
		System.out.println("---------------------\nI tuoi acquisti:\n");

		PreparedStatement pStmt = conn.prepareStatement("SELECT o.pDate, o.product, p.price FROM orders o, products p WHERE user = ? AND paid = 1 AND o.product = p.name");
		pStmt.setString(1, username);
		ResultSet res = pStmt.executeQuery();

		if (!res.isBeforeFirst()) {
			System.out.println("Ancora nessun acquisto.");
		}
		else {
			while (res.next()) {
				String dt = res.getString(1);
				String p = res.getString(2);
				String pr = res.getString(3);
				System.out.println(dt + " - " + p +", " + pr + " euro.");
			}
		}

		res.close();
		pStmt.close();

		// prodotti disponibili
		System.out.println("---------------------\nCatalogo prodotti:\n");
		catalog(conn);
		System.out.println("---------------------");
	}

	public static void main(String [] args) {
		Connection conn = null;
		PreparedStatement pStmt = null;
		Console console = System.console();
		try {
			Class.forName("org.sqlite.JDBC");
			String dbName = "ecommerce.db";
			conn = DriverManager.getConnection("jdbc:sqlite:" + dbName);

			String name = "";
			BigDecimal maxExp = new BigDecimal("1000");
			String lastLogin = "";

			System.out.println("#####################################################");
			System.out.println("####### Benvenuto nel nostro negozio virtuale #######");
			System.out.println("#####################################################");

			String username = console.readLine("Username: ");
			String sql = "SELECT name, surname, password, maxExp, regDate, lastLogin FROM users WHERE username = ?";

			pStmt = conn.prepareStatement(sql);
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

				try {
					String d = console.readLine("Limite di spesa: ");
					maxExp = new BigDecimal(d);
				} catch (NumberFormatException e) {
					System.err.println(e);
				}

				pStmt = conn.prepareStatement("INSERT INTO users (username, password, name, surname, maxExp, regDate, lastLogin) VALUES (?, ?, ?, ?, ?, ?, ?)");

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

				pStmt.setBigDecimal(5, maxExp);

				SimpleDateFormat fmt = new SimpleDateFormat("dd-MM-yyyy HH:mm:ss");
				String date = fmt.format(new Date());

				pStmt.setString(6, date);
				pStmt.setString(7, date);
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
						System.out.println("Password non corretta!");
						if (i < 3) continue;
						else {
							System.err.println("Tre tentativi di autenticazione fallita: stop.");
							return;
						}
					}

					auth = true;
					pStmt = conn.prepareStatement("UPDATE users SET lastLogin = ? WHERE username = ?");
					SimpleDateFormat fmt = new SimpleDateFormat("dd-MM-yyyy HH:mm:ss");
					String date = fmt.format(new Date());
					pStmt.setString(1, date);
					pStmt.setString(2, username);
					pStmt.executeUpdate();
					pStmt.close();
				}

				// nome
				name = res.getString(1);
				// limite di spesa
				maxExp = res.getBigDecimal(4);
				lastLogin = res.getString(6);
				res.close();
			}

			System.out.println("Bentornato, " + name + "!\nCredito disponibile: " + maxExp + " euro.");
			System.out.println("Ultimo accesso effettuato il " + lastLogin + ".");

			summary(conn, username);

			while (true) {
				System.out.println("Operazioni disponibili:\n");
				System.out.println("1. Nuovo ordine.");
				System.out.println("2. Checkup di un ordine.");
				System.out.println("3. Ricarica credito spesa.");
				System.out.println("4. Riassunto");
				System.out.println("5. Esci\n");

				String oper = console.readLine("Scegli l'operazione (1, 2, 3, 4, 5): ");

				if (oper.equals("1")) {
					System.out.println("Disponibili all'acquisto:\n");
					catalog(conn);
					System.out.print(System.lineSeparator());

					String opt = console.readLine("Cosa vuoi aggiungere al carrello? ");

					pStmt = conn.prepareStatement("SELECT price FROM products WHERE name = ?");
					pStmt.setString(1, opt);
					res = pStmt.executeQuery();

					if (!res.isBeforeFirst()) {
						System.out.println("Prodotto non trovato!\n");
						continue;
					}

					String p = console.readLine("Trovato \"" + opt + "\". Vuoi pagare subito? ").toLowerCase();

					if (p.equals("s")) {
						BigDecimal price = res.getBigDecimal(1);
						maxExp = maxExp.subtract(price);
						res.close();

						conn.setAutoCommit(false);
						pStmt = conn.prepareStatement("UPDATE users SET maxExp = ? WHERE username = ?");
						pStmt.setBigDecimal(1, maxExp);
						pStmt.setString(2, username);
						pStmt.executeUpdate();
						pStmt.close();

						pStmt = conn.prepareStatement("INSERT INTO orders (user, product, paid, pDate) VALUES (?, ?, ?, ?)");
						pStmt.setString(1, username);
						pStmt.setString(2, opt);
						pStmt.setInt(3, 1);

						SimpleDateFormat fmt = new SimpleDateFormat("dd-MM-yyyy HH:mm:ss");
						String date = fmt.format(new Date());

						pStmt.setString(4, date);
						pStmt.executeUpdate();
						pStmt.close();

						conn.commit();
						conn.setAutoCommit(true);
					}
					else {
						pStmt = conn.prepareStatement("INSERT INTO orders (user, product, paid) VALUES (?, ?, ?)");
						pStmt.setString(1, username);
						pStmt.setString(2, opt);
						pStmt.setInt(3, 0);
						pStmt.executeUpdate();
						pStmt.close();
					}
				}
				else if (oper.equals("2")) {
					System.out.println("Ordini nel carrello:\n");

					if (!listOrd(conn, username)) {
						System.out.print(System.lineSeparator());
						continue;
					}

					System.out.print(System.lineSeparator());
					String s = console.readLine("Numero ordine da finalizzare: ");

					// seleziona il prezzo dell'ordine da evadere
					pStmt = conn.prepareStatement("SELECT p.price FROM orders o, products p WHERE o.id = ? AND o.product = p.name AND o.paid = 0");
					int oid = -1;
					try {
						oid = Integer.parseInt(s);
					}
					catch (NumberFormatException e) {
						System.err.println(e);
					}

					pStmt.setInt(1, oid);
					res = pStmt.executeQuery();
					if (!res.isBeforeFirst()) {
						System.err.println("Ordine non trovato!\n");
						continue;
					}

					BigDecimal price = res.getBigDecimal(1);
					maxExp = maxExp.subtract(price);
					res.close();
					int records = 0;

					conn.setAutoCommit(false);

					pStmt = conn.prepareStatement("UPDATE users SET maxExp = ? WHERE username = ?");
					pStmt.setBigDecimal(1, maxExp);
					pStmt.setString(2, username);
					records += pStmt.executeUpdate();
					pStmt.close();

					pStmt = conn.prepareStatement("UPDATE orders SET paid = ?, pDate = ? WHERE id = ?");
					pStmt.setInt(1, 1);
					SimpleDateFormat fmt = new SimpleDateFormat("dd-MM-yyyy HH:mm:ss");
					String date = fmt.format(new Date());
					pStmt.setString(2, date);
					pStmt.setInt(3, oid);
					records += pStmt.executeUpdate();
					pStmt.close();

					conn.commit();
					conn.setAutoCommit(true);

					if (records > 0) {
						System.out.println("Pagato " + price + " euro. Credito residuo: " + maxExp + " euro");
					}
				}
				else if (oper.equals("3")) {
					String imp = console.readLine("Importo ricarica: ");
					try {
						BigDecimal v = new BigDecimal(imp);

						if (v.add(maxExp).compareTo(new BigDecimal("10000")) <= 0) {
							maxExp = maxExp.add(v);
							System.out.println("Hai ricaricato " + imp + ". Credito attuale: " + maxExp);
							pStmt = conn.prepareStatement("UPDATE users SET maxExp = ? WHERE username = ?");
							pStmt.setBigDecimal(1, maxExp);
							pStmt.setString(1, username);
							pStmt.executeUpdate();
							pStmt.close();
						}
					}
					catch (NumberFormatException e) {
						System.err.println(e);
					}
				}
				else if (oper.equals("4")) {
					summary(conn, username);
				}
				else if (oper.equals("5")) {
					System.out.println("Ciao " + name + ", grazie di aver utilizzato i nostri servizi. A presto!");
					return;
				}
				else {
					System.out.println("Operazione sconosciuta!\n");
				}
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

