/*
file Esercizio29.java
eseguire con: java -cp .:sqlitejdbc-v<nnn>.jar Esercizio29
*/

import java.sql.DriverManager;
import java.sql.Connection;
import java.sql.Statement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.Date;

public class Esercizio29 {
	public static void main(String [] args) {
		Connection conn = null;
		Statement stmt = null;
		try {
			Class.forName("org.sqlite.JDBC");
			String dbName = "ecommerce.db";
			conn = DriverManager.getConnection("jdbc:sqlite:" + dbName);
			stmt = conn.createStatement();

			conn.setAutoCommit(false);

			stmt.addBatch("PRAGMA foreign_keys = ON;");
			stmt.addBatch("CREATE TABLE users (id INTEGER PRIMARY KEY, username VARCHAR(50) UNIQUE NOT NULL, password VARCHAR(50) NOT NULL, name VARCHAR(50) NOT NULL, surname VARCHAR(50) NOT NULL, maxExp REAL NOT NULL, r_date TIMESTAMP, llogin TIMESTAMP);");
			stmt.addBatch("CREATE TABLE products (name VARCHAR(255) PRIMARY KEY, price REAL);");
			stmt.addBatch("CREATE TABLE orders (id INTEGER PRIMARY KEY, user VARCHAR(50), product VARCHAR(255), paid BIT, pDate TIMESTAMP, FOREIGN KEY(user) REFERENCES users(username), FOREIGN KEY(product) REFERENCES products(name));");
			stmt.addBatch("INSERT INTO products (name, price) VALUES ('Apple IPhone', 1000);");
			stmt.addBatch("INSERT INTO products (name, price) VALUES ('Apple IPad Pro', 399);");
			stmt.addBatch("INSERT INTO products (name, price) VALUES ('Apple MacPro', 6599);");
			stmt.addBatch("INSERT INTO products (name, price) VALUES ('Lenovo ThinkPad', 1159);");
			stmt.addBatch("INSERT INTO products (name, price) VALUES ('Lenovo P', 1348.9);");

			stmt.executeBatch();
			stmt.close();
			conn.commit();
			conn.setAutoCommit(true);

			System.out.println("Create le tabelle di utenti, prodotti e ordini.");
		}
		catch (ClassNotFoundException e) {
			System.err.println(e);
		}
		catch (SQLException e) {
			System.err.println(e);
		}
		finally {
			try {
				if (stmt != null) stmt.close();
				if (conn != null) conn.close();
			}
			catch (SQLException e) {
				System.err.println(e);
			}
		}
	}
}

