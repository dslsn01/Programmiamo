# file esercizio30.py

from __future__ import print_function
if hasattr(__builtins__, 'raw_input'): input = raw_input
from datetime import datetime
import sqlite3
from sys import stdout
from os import linesep

def listOrd(cursor):
	rc = False
	cursor.execute("SELECT o.id, o.product, p.price FROM orders o, products p WHERE user = ? AND o.product = p.name AND o.paid = 0", (username,))
	res = cursor.fetchall()
	if not res:
		print("[X] Nessun ordine presente.")
	else:
		rc = True
		for record in res:
			print("[{}] {} - {} euro.".format(record[0], record[1], record[2]))

	return rc

def catalog(cursor):
	cursor.execute("SELECT name, price FROM products")
	for record in cursor.fetchall():
		print("{} - {} euro.".format(record[0], record[1]))

def summary(cursor):
	# ordini (da pagare)
	print("---------------------\nI tuoi ordini:\n")
	listOrd(cursor)

	# acquisti passati
	print("---------------------\nI tuoi acquisti:\n")

	cursor.execute("SELECT o.pDate, o.product, p.price FROM orders o, products p WHERE user = ? AND paid = 1 AND o.product = p.name", (username,))
	res = cursor.fetchall()

	if not res:
		print("[X] Ancora nessun acquisto.")
	else:
		for record in res:
			dt = record[0].strftime("%d/%m/%Y")
			print("{} - {}, {} euro.".format(dt, record[1], record[2]))

	# prodotti disponibili
	print("---------------------\nCatalogo prodotti:\n")
	catalog(cursor)
	print("---------------------")

conn = sqlite3.connect("ecommerce.db", detect_types=sqlite3.PARSE_DECLTYPES | sqlite3.PARSE_COLNAMES)
cursor = conn.cursor()

try:
	# nome, ultimo login e limite di spesa
	name = ""
	maxExp = 1000
	llogin = None

	print("#####################################################")
	print("####### Benvenuto nel nostro negozio virtuale #######")
	print("#####################################################")

	username = input("Username: ").lower()

	pStmt = "SELECT name, surname, password, maxExp, r_date, llogin FROM users WHERE username = ?"

	cursor.execute(pStmt, (username,))
	res = cursor.fetchone()

	if not res:
		opt = input("Username \"{}\" non presente! Vuoi registrarti? s | n: ".format(username)).lower()

		if opt != "s": exit()

		pStmt = "INSERT INTO users (username, password, name, surname, maxExp, r_date, llogin) VALUES (?, ?, ?, ?, ?, ?, ?)"

		pwd = input("Password: ") or None
		name = input("Nome: ") or None
		surname = input("Cognome: ") or None
		maxExp = input("Limite di spesa: ")

		r_date = datetime.now().replace(microsecond=0)
		llogin = r_date
		cursor.execute(pStmt, (username, pwd, name, surname, maxExp, r_date, llogin))
		conn.commit()
	else:
		auth = False
		i = 0 # numero tentativi di autenticazione
		_pwd = res[2]
		while not auth:
			pwd = input("Password: ")
			if pwd != _pwd:
				i += 1
				print("Password non corretta!")
				if i < 3: continue
				else:
					print("Tre tentativi di autenticazione fallita: stop.")
					exit()

			auth = True

			cursor.execute("UPDATE users SET llogin = CURRENT_TIMESTAMP WHERE username = ?", (username,))
			conn.commit()

		name = res[0]
		maxExp = res[3]
		llogin = res[5]

	print("++++++++++++++++++++++++++++++++++")
	print("Benvenuto, {}!\nCredito disponibile: {} euro.".format(name, maxExp))
	print("Ultimo accesso effettuato il {}.".format(llogin.strftime("%d/%m/%Y %H:%M:%S")))

	summary(cursor)

	while True:
		print("Operazioni disponibili:\n")
		print("1. Nuovo ordine.")
		print("2. Checkup di un ordine.")
		print("3. Ricarica credito spesa.")
		print("4. Riassunto")
		print("5. Esci\n")

		oper = input("Scegli l'operazione (1, 2, 3, 4, 5): ")

		if oper == "1":
			print("Disponibili all'acquisto:\n")
			catalog(cursor)
			stdout.write(linesep)

			opt = input("Cosa vuoi aggiungere al carrello? ")

			cursor.execute("SELECT price FROM products WHERE name = ?", (opt,))
			res = cursor.fetchone()

			if not res:
				print("Prodotto non trovato!\n")
				continue

			p = input("Trovato \"{}\". Vuoi pagare subito? ".format(opt)).lower()
			if p == "s":
				price = res[0]
				maxExp -= price
				cursor.execute("UPDATE users SET maxExp = ? WHERE username = ?", (maxExp, username))
				cursor.execute("INSERT INTO orders (user, product, paid, pDate) VALUES (?, ?, ?, CURRENT_TIMESTAMP)", (username, opt, 1))
			else:
				cursor.execute("INSERT INTO orders (user, product, paid) VALUES (?, ?, ?)", (username, opt, 0))

			conn.commit()
			stdout.write(linesep)

		elif oper == "2":
			print("Ordini nel carrello:\n")

			if not listOrd(cursor):
				stdout.write(linesep)
				continue;

			oid = input("\nNumero ordine da finalizzare: ")

			# seleziona il prezzo dell'ordine da evadere
			cursor.execute("SELECT p.price FROM orders o, products p WHERE o.id = ? AND o.product = p.name AND o.paid = 0", (oid,))
			res = cursor.fetchone()
			if not res:
				print("Ordine non trovato!\n")
				continue

			price = res[0]
			maxExp -= price
			cursor.execute("UPDATE users SET maxExp = ? WHERE username = ?", (maxExp, username))
			cursor.execute("UPDATE orders SET paid = ?, pDate = CURRENT_TIMESTAMP WHERE id = ?", (1, oid))

			records = cursor.rowcount

			if records > 0:
				conn.commit()
				print("Pagato {} euro. Credito residuo: {} euro".format(res[0], maxExp))

		elif oper == "3":
			imp = input("Importo ricarica: ")
			try:
				v = int(imp)
				if v + maxExp <= 10000:
					maxExp += v
				ursor.execute("UPDATE users SET maxExp = ? WHERE username = ?", (maxExp, username))
				conn.commit()
				print("Hai ricaricato {}. Credito attuale: {}".format(imp, maxExp))
			except ValueError as e:
				print(e)

		elif oper == "4":
			summary(cursor)
		elif oper == "5":
			print("Ciao {}, grazie di aver utilizzato i nostri servizi. A presto!".format(name))
			exit()
		else:
			print("Operazione sconosciuta!\n")

except sqlite3.OperationalError as e:
	print(e)

