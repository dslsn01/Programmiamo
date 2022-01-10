/*
file Esercizio28.java
eseguire con: java -cp .:sqlitejdbc-v<nnn>.jar Esercizio28
*/

import java.io.Console;
import java.math.BigDecimal;
import java.sql.DriverManager;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.text.SimpleDateFormat;
import java.text.ParseException;
import java.util.Calendar;
import java.util.Date;

public class Esercizio28 {
	public static void main(String [] args) {
		Connection conn = null;
		PreparedStatement pStmt = null;
		ResultSet res = null;

		System.out.println("##############################################");
		System.out.println("####### Benvenuto nel sito della banca #######");
		System.out.println("##############################################");

		try {
			Class.forName("org.sqlite.JDBC");
			String dbName = "bank.db";
			conn = DriverManager.getConnection("jdbc:sqlite:" + dbName);

			Console console = System.console();

			String ucode = console.readLine("Codice utente: ");
			pStmt = conn.prepareStatement("SELECT n_acc, iban, password, ident, bal FROM customers WHERE ucode = ?");
			pStmt.setString(1, ucode);
			res = pStmt.executeQuery();

			if (!res.isBeforeFirst()) {
				System.err.println("Utente \"" + ucode + "\" non presente!");
				return;
			}

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

			String n_acc = res.getString(1);
			String iban = res.getString(2);
			String ident = res.getString(4);
			BigDecimal bal = res.getBigDecimal(5);

			res.close();
			pStmt.close();

			System.out.println("Benvenuto, " + ident + "!\nN. conto: " + n_acc + " IBAN: " + iban);
			System.out.println("Saldo conto: " + bal + " euro.");

			while (true) {
				System.out.println("Operazioni disponibili:\n");
				System.out.println("1. Lista movimenti.");
				System.out.println("2. Bonifico.");
				System.out.println("3. Esplora conto deposito.");
				System.out.println("4. Esci\n");

				String oper = console.readLine("Scegli l'operazione (1, 2, 3, 4): ");

				if (oper.equals("1")) {
					System.out.println("Lista movimenti\n");
					pStmt = conn.prepareStatement("SELECT ord, imp, desc, v_date, o_date FROM mov WHERE (ord = ? OR ben = ?)");
					pStmt.setString(1, iban);
					pStmt.setString(2, iban);
					res = pStmt.executeQuery();

					if (!res.isBeforeFirst()) {
						System.out.println("Nessun movimento recente.");
						continue;
					}

					while (res.next()) {
						String ord = res.getString(1);
						BigDecimal imp = res.getBigDecimal(2);
						imp = ord.equals(iban) ? imp.negate() : imp;
						String desc = res.getString(3);
						String v_date = res.getString(4);
						String o_date = res.getString(5);

						try {
							SimpleDateFormat fmt = new SimpleDateFormat("yyyy-MM-dd");
							v_date = new SimpleDateFormat("dd/MM/yyyy").format(fmt.parse(v_date));
							o_date = new SimpleDateFormat("dd/MM/yyyy").format(fmt.parse(o_date));
							System.out.println(imp + " euro - \"" + desc + "\", data valuta: " + v_date + " data operativa: " + o_date);
						} catch (ParseException e) {
							System.err.println(e);
						}
					}

					System.out.print(System.lineSeparator());
				}
				else if (oper.equals("2")) {
					System.out.println("Bonifico");

					String b_iban = console.readLine("IBAN beneficiario: ");

					if (b_iban.equals(iban)) continue;

					pStmt = conn.prepareStatement("SELECT ident, bal FROM customers WHERE iban = ?");
					pStmt.setString(1, b_iban);
					res = pStmt.executeQuery();
					BigDecimal dBal = new BigDecimal(0);

					if (!res.isBeforeFirst()) {
						System.err.println("IBAN non esistente!");
						continue;
					}

					String b = res.getString(1);
					System.out.println("Beneficiario: " + b);
					dBal = res.getBigDecimal(2);

					res.close();
					pStmt.close();

					String s = console.readLine("Importo bonifico: ");

					BigDecimal imp = new BigDecimal(0);
					try {
						imp = new BigDecimal(s);
						if (bal.subtract(imp).compareTo(BigDecimal.ZERO) < 0) {
							System.out.println("Conto incapiente!");
							continue;
						}
						bal = bal.subtract(imp);
						dBal = dBal.add(imp);
					}
					catch (NumberFormatException e) {
						System.err.println(e);
						continue;
					}

					String desc = console.readLine("Descrizione/causale: ");

					int rowcount = 0;
					conn.setAutoCommit(false);

					pStmt = conn.prepareStatement("UPDATE customers SET bal = ? WHERE iban = ?");
					pStmt.setBigDecimal(1, bal);
					pStmt.setString(2, iban);
					rowcount += pStmt.executeUpdate();
					pStmt.close();

					pStmt = conn.prepareStatement("INSERT INTO mov (ord, ben, imp, desc, v_date, o_date) VALUES (?, ?, ?, ?, ?, ?)");
					pStmt.setString(1, iban);
					pStmt.setString(2, b_iban);
					pStmt.setBigDecimal(3, imp);
					pStmt.setString(4, desc);

					Date dt = new Date();
					SimpleDateFormat fmt = new SimpleDateFormat("yyyy-MM-dd");
					String v_date = fmt.format(dt);

					Calendar cal = Calendar.getInstance();
					cal.setTime(dt);
					cal.add(Calendar.DATE, 3);
					String o_date = fmt.format(cal.getTime());

					pStmt.setString(5, v_date);
					pStmt.setString(6, o_date);
					rowcount += pStmt.executeUpdate();
					pStmt.close();

					pStmt = conn.prepareStatement("UPDATE customers SET bal = ? WHERE iban = ?");
					pStmt.setBigDecimal(1, dBal);
					pStmt.setString(2, b_iban);
					rowcount += pStmt.executeUpdate();
					pStmt.close();

					if (rowcount > 0) {
						conn.commit();
						System.out.println("Inviato bonifico di " + imp + " euro a " + b + ".");
					}

					conn.setAutoCommit(true);
					System.out.print(System.lineSeparator());
				}
				else if (oper.equals("3")) {
					System.out.println("Esplora conto deposito");

					pStmt = conn.prepareStatement("SELECT bal FROM deposit WHERE cc = ?");
					pStmt.setString(1, n_acc);
					res = pStmt.executeQuery();

					BigDecimal imp = new BigDecimal(0);
					BigDecimal dBal = new BigDecimal(0);

					if (!res.isBeforeFirst()) {
						res.close();
						pStmt.close();

						String opt = console.readLine("Conto deposito non ancora aperto. Si desidera aprirlo? s | n: ").toLowerCase();

						if (!opt.equals("s")) continue;

						pStmt = conn.prepareStatement("INSERT INTO deposit (cc, bal) VALUES (?, 0)");
						pStmt.setString(1, n_acc);
						pStmt.executeUpdate();
						pStmt.close();
					}
					else {
						// saldo conto deposito
						dBal = res.getBigDecimal(1);
						res.close();
						pStmt.close();
					}

					System.out.println("Operazioni disponibili:\n");
					System.out.println("a. Trasferisci fondi da conto corrente a conto deposito.");
					System.out.println("b. Trasferisci fondi da conto deposito a conto corrente.\n");

					String op = console.readLine("Scegli l'operazione (a/b): ");

					if (!op.equals("a") && !op.equals("b")) {
						System.out.println("Operazione sconosciuta!");
						continue;
					}

					String s = console.readLine("Importo: ");

					try {
						imp = new BigDecimal(s);
					}
					catch (NumberFormatException e) {
						System.err.println(e);
						continue;
					}

					if (op.equals("a")) {
						if (bal.subtract(imp).compareTo(BigDecimal.ZERO) >= 0) {
							// decrementa saldo conto corrente
							bal = bal.subtract(imp);
							// incrementa saldo conto deposito
							dBal = dBal.add(imp);
						} else {
							System.err.println("Importo non disponibile su conto corrente!");
							continue;
						}
					}
					else {
						if (dBal.subtract(imp).compareTo(BigDecimal.ZERO) >= 0) {
							dBal = dBal.subtract(imp);
							bal = bal.add(imp);
						} else {
							System.err.println("Importo non disponibile su conto deposito!");
							continue;
						}
					}

					int rowcount = 0;
					conn.setAutoCommit(false);

					pStmt = conn.prepareStatement("UPDATE customers SET bal = ? WHERE n_acc = ?");
					pStmt.setBigDecimal(1, bal);
					pStmt.setString(2, n_acc);
					rowcount += pStmt.executeUpdate();
					pStmt.close();

					pStmt = conn.prepareStatement("UPDATE deposit SET bal = ? WHERE cc = ?");
					pStmt.setBigDecimal(1, dBal);
					pStmt.setString(2, n_acc);
					rowcount += pStmt.executeUpdate();
					pStmt.close();

					if (rowcount > 0) {
						conn.commit();
						System.out.println("Inviato bonifico di " + imp + " euro a " + ident + ".");
					}

					conn.setAutoCommit(true);
					System.out.print(System.lineSeparator());

					String msg = op.equals("b") ? "corrente" : "deposito";
					System.out.println("Trasferiti " + imp + " euro su conto " + msg + "." + System.lineSeparator());
				}
				else if (oper.equals("4")) {
					System.out.println("Grazie di aver utilizzato i servizi della banca.");
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
				if (res != null) res.close();
				if (pStmt != null) pStmt.close();
				if (conn != null) conn.close();
			}
			catch (SQLException e) {
				System.err.println(e);
			}
		}
	}
}

