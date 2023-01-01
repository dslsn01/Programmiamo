/*
file Esercizio26.java
eseguire con: java -cp .:sqlitejdbc-v<nnn>.jar Esercizio26
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
import java.util.Calendar;
import java.util.Date;

public class Esercizio26 {
	public static void main(String [] args) {
		Connection conn = null;
		Statement stmt = null;
		PreparedStatement pStmt = null;
		ResultSet res = null;

		System.out.println("#####################################################");
		System.out.println("######## Amministrazione clienti della banca ########");
		System.out.println("#####################################################");

		try {
			Class.forName("org.sqlite.JDBC");
			String dbName = "bank.db";
			conn = DriverManager.getConnection("jdbc:sqlite:" + dbName);
			stmt = conn.createStatement();

			res = stmt.executeQuery("SELECT n_acc, ident, bal FROM customers");

			while (res.next()) {
				System.out.println("[" + res.getString(1) + "] - " + res.getString(2) + ", " + res.getDouble(3) + " euro.");
			}

			res.close();
			Console console = System.console();

			while (true) {
				System.out.println("Registra un nuovo movimento (entrata / uscita): ");
				String cc = console.readLine("Numero conto: ");

				if (cc.isEmpty()) return;

				pStmt = conn.prepareStatement("SELECT bal, iban FROM customers WHERE n_acc = ?");
				pStmt.setString(1, cc);
				res = pStmt.executeQuery();

				if (!res.isBeforeFirst()) {
					System.err.println("!!! Conto non esistente!");
					res.close();
					pStmt.close();
					continue;
				}

				// saldo conto corrente
				BigDecimal pbal = res.getBigDecimal(1);
				String iban = res.getString(2);
				BigDecimal sbal = new BigDecimal("0.0");
				BigDecimal imp = new BigDecimal("0.0");
				String i = console.readLine("Importo (accredito o addebito): ");

				try {
					imp = new BigDecimal(i);
					pbal = pbal.add(imp);
				}
				catch (NumberFormatException e) {
					System.err.println(e);
					continue;
				}

				if (imp.compareTo(BigDecimal.ZERO) == 0) {
					System.err.println("!!! Importo non valido!");
					continue;
				}

				// IBAN letto da tastiera
				String s = null;
				// IBAN ordinante e beneficiario
				String o_iban = null;
				String b_iban = null;

				// movimento in uscita
				if (imp.compareTo(BigDecimal.ZERO) < 0) {
					s = console.readLine("IBAN beneficiario (27 cifre): ");
					if (s.isEmpty()) {
						System.err.println("!!! IBAN beneficiario nullo!");
						continue;
					}
					// iban del beneficiario
					b_iban = s;
					// IBAN associato a conto corrente
					o_iban = iban;
				}
				// movimento in entrata
				else if (imp.compareTo(BigDecimal.ZERO) > 0) {
					s = console.readLine("IBAN ordinante (27 cifre): ");
					if (s.isEmpty()) {
						System.err.println("!!! IBAN ordinante nullo!");
						continue;
					}
					// iban dell'ordinante
					o_iban = s;
					// IBAN associato a conto corrente
					b_iban = iban;
				}

				res.close();
				pStmt.close();

				if (o_iban.equals(b_iban)) {
					System.err.println("!!! IBAN di ordinante e beneficiario coincidono!");
					continue;
				}

				// recupera le coordinate del secondo conto
				pStmt = conn.prepareStatement("SELECT bal FROM customers WHERE iban = ?");
				pStmt.setString(1, s);
				res = pStmt.executeQuery();

				if (!res.isBeforeFirst()) {
					System.out.println("!!! Conto non esistente!");
					res.close();
					pStmt.close();
					continue;
				}

				// incrementa/decrementa il saldo dell'altro conto corrente
				sbal = res.getBigDecimal(1).subtract(imp);
				System.out.println("sbal: " + sbal);

				pStmt.close();

				String desc = console.readLine("Descrizione/causale: ");

				conn.setAutoCommit(false);
				pStmt = conn.prepareStatement("INSERT INTO mov (ord, ben, imp, desc, v_date, o_date) VALUES (?, ?, ?, ?, ?, ?)");
				pStmt.setString(1, o_iban);
				pStmt.setString(2, b_iban);
				// l'importo del movimento viene registrato in valore assoluto
				pStmt.setBigDecimal(3, imp.abs());
				pStmt.setString(4, desc);

				SimpleDateFormat fmt = new SimpleDateFormat("yyyy-MM-dd");
				Date dt = new Date();
				String v_date = fmt.format(dt);

				Calendar cal = Calendar.getInstance();
				cal.setTime(dt);
				cal.add(Calendar.DATE, 3);
				String o_date = fmt.format(cal.getTime());

				pStmt.setString(5, v_date);
				pStmt.setString(6, o_date);

				pStmt.executeUpdate();
				pStmt.close();

				// aggiorna entrambi i conti
				pStmt = conn.prepareStatement("UPDATE customers SET bal = ? WHERE n_acc = ?");
				pStmt.setBigDecimal(1, pbal);
				pStmt.setString(2, cc);
				pStmt.executeUpdate();
				pStmt.close();

				pStmt = conn.prepareStatement("UPDATE customers SET bal = ? WHERE iban = ?");
				pStmt.setBigDecimal(1, sbal);
				pStmt.setString(2, s);
				pStmt.executeUpdate();
				pStmt.close();

				conn.commit();
				conn.setAutoCommit(true);
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
				if (pStmt != null) pStmt.close();
				if (conn != null) conn.close();
			}
			catch (SQLException e) {
				System.err.println(e);
			}
		}
	}
}

