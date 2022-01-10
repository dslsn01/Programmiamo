# file esercizio28.py

from __future__ import print_function
if hasattr(__builtins__, 'raw_input'): input = raw_input
from datetime import date, datetime, timedelta
from sys import stdout
from os import linesep
import sqlite3

print("##############################################")
print("####### Benvenuto nel sito della banca #######")
print("##############################################")

conn = sqlite3.connect("bank.db", detect_types=sqlite3.PARSE_DECLTYPES | sqlite3.PARSE_COLNAMES)
cursor = conn.cursor()

ucode = input("Codice utente: ")

try:
	pStmt = "SELECT n_acc, iban, password, ident, bal FROM customers WHERE ucode = ?"

	cursor.execute(pStmt, (ucode,))
	res = cursor.fetchone()

	if not res:
		print("Utente \"{}\" non presente!".format(ucode))
		exit()

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

		n_acc = res[0]
		iban = res[1]
		ident = res[3]
		bal = res[4]

	print("Benvenuto, {}!\nN. conto: {} IBAN: {}".format(ident, n_acc, iban))
	print("Saldo conto: {} euro.".format(bal))

	while True:
		print("Operazioni disponibili:\n")
		print("1. Lista movimenti.")
		print("2. Bonifico.")
		print("3. Esplora conto deposito.")
		print("4. Esci\n")

		oper = input("Scegli l'operazione (1, 2, 3, 4): ")

		if oper == "1":
			print("Lista movimenti\n")

			cursor.execute("SELECT ord, imp, desc, v_date, o_date FROM mov WHERE (ord = ? OR ben = ?)", (iban, iban,))
			res = cursor.fetchall()

			if not res:
				print("[X] Nessun movimento recente.\n")
				continue

			for m in res:
				imp = m[1]
				# i versamenti sono movimenti negativi
				imp = -imp if m[0] == iban else imp
				desc = m[2]
				v_date = m[3].strftime("%d/%m/%Y")
				o_date = m[4].strftime("%d/%m/%Y")
				print("{} euro - \"{}\", data valuta: {} data operativa: {}".format(imp, desc, v_date, o_date))
			stdout.write(linesep)

		elif oper == "2":
			print("Bonifico")
			b_iban = input("IBAN beneficiario: ")

			if b_iban == iban: continue

			cursor.execute("SELECT ident, bal FROM customers WHERE iban = ?", (b_iban,))

			d_bal = 0.0
			cc = cursor.fetchone()

			if not cc:
				print("!!! Conto non esistente!")
				continue

			print("Beneficiario: {}".format(cc[0]))
			d_id = cc[0]
			d_bal = cc[1]

			s = input("Importo bonifico: ")
			try:
				imp = abs(float(s))
				if bal - imp < 0:
					print("!!! Conto incapiente!")
					continue

				bal -= imp
				d_bal += imp
			except ValueError as e:
				print(e)
				continue

			desc = input("Descrizione/causale: ")

			# aggiorna saldo conto corrente, tabella movimenti, saldo conto destinatario?
			cursor.execute("UPDATE customers SET bal = ? WHERE iban = ?", (bal, iban,))
			v_date = date.today()
			o_date = v_date + timedelta(days=3)
			cursor.execute("INSERT INTO mov (ord, ben, imp, desc, v_date, o_date) VALUES (?, ?, ?, ?, ?, ?)", (iban, b_iban, imp, desc, v_date, o_date))
			cursor.execute("UPDATE customers SET bal = ? WHERE iban = ?", (d_bal, b_iban,))
			conn.commit()

			if cursor.rowcount > 0:
				conn.commit()
				print("Inviato bonifico di {} euro a {}.\n".format(imp, d_id))

		elif oper == "3":
			print("Esplora conto deposito")
			cursor.execute("SELECT bal FROM deposit WHERE cc = ?", (n_acc,))
			res = cursor.fetchone()
			if not res:
				opt = input("Conto deposito non ancora aperto. Si desidera aprirlo? s | n: ").lower()

				if opt != "s": continue

				cursor.execute("INSERT INTO deposit (cc, bal) VALUES (?, 0)", (n_acc,))
				conn.commit()
			else:
				# saldo conto deposito
				d_bal = res[0]

			print("Operazioni disponibili:\n")
			print("a. Trasferisci fondi da conto corrente a conto deposito.")
			print("b. Trasferisci fondi da conto deposito a conto corrente.\n")

			op = input("Scegli l'operazione (a/b): ")

			if op not in ('a', 'b'):
				print("Operazione sconosciuta!")
				continue;

			# se a: 1\ seleziona saldo corrente, 2\ chiedi importo

			s = input("Importo: ")

			try:
				imp = float(s)
			except ValueError as e:
				print(e)
				continue

			if op == 'a':
				if bal - imp >= 0:
					# decrementa saldo conto corrente
					bal -= imp
					# incrementa saldo conto deposito
					d_bal += imp
				else:
					print("Importo non disponibile su conto corrente!")
					continue
			else:
				if d_bal - imp >= 0:
					d_bal -= imp
					bal += imp
				else:
					print("Importo non disponibile su conto deposito!")
					continue

			cursor.execute("UPDATE customers SET bal = ? WHERE n_acc = ?", (bal, n_acc,))
			cursor.execute("UPDATE deposit SET bal = ? WHERE cc = ?", (d_bal, n_acc,))
			conn.commit()

			msg = "corrente" if op == 'b' else "deposito"
			print("Hai trasferito {} euro su conto {}.\n".format(imp, msg))

		elif oper == "4":
			print("Grazie di aver utilizzato i servizi della banca.")
			exit()
		else:
			print("Operazione sconosciuta!\n")

except sqlite3.OperationalError as e:
	print(e)

