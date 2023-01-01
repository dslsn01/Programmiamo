# file esercizio26.py

from __future__ import print_function
if hasattr(__builtins__, 'raw_input'): input = raw_input
from datetime import date, timedelta
from sys import stdout
from os import linesep
import sqlite3

print("#####################################################")
print("######## Amministrazione clienti della banca ########")
print("#####################################################")

conn = sqlite3.connect("bank.db", detect_types=sqlite3.PARSE_DECLTYPES | sqlite3.PARSE_COLNAMES)
cursor = conn.cursor()

try:
	cursor.execute("SELECT n_acc, ident, bal FROM customers")

	for c in cursor.fetchall():
		print("[{}] - {}, {} euro.".format(c[0], c[1], c[2]))

	while True:
		print("Registra un nuovo movimento (entrata / uscita): ")
		cc = input("Numero conto: ")

		if not cc: exit()

		c1 = cursor.execute("SELECT bal, iban FROM customers WHERE n_acc = ?", (cc,)).fetchone()

		if not c1:
			print("!!! Conto non esistente!")
			continue

		# saldo conto corrente
		pbal = c1[0]
		iban = c1[1]
		sbal = 0.0
		imp = 0.0
		s = input("Importo (accredito o addebito): ")

		# incrementa o decrementa il saldo
		try:
			imp = float(s)
			pbal += imp
		except ValueError as e:
			print(e)
			continue

		if not imp:
			print("!!! Importo non valido!")
			continue

		# movimento in uscita
		if imp < 0:
			s = input("IBAN beneficiario (27 cifre): ")
			if not s:
				print("!!! IBAN beneficiario nullo!")
				continue

			b_iban = s
			# IBAN associato a conto corrente
			o_iban = iban

		# movimento in entrata
		elif imp > 0:
			s = input("IBAN ordinante (27 cifre): ")
			if not s:
				print("!!! IBAN ordinante nullo!")
				continue

			o_iban = s
			# IBAN associato a conto corrente
			b_iban = iban

		if s == iban:
			print("!!! IBAN di ordinante e beneficiario coincidono!")
			continue

		# recupera le coordinate del secondo conto
		c2 = cursor.execute("SELECT bal FROM customers WHERE iban = ?", (s,)).fetchone()

		if not c2:
			print("!!! Conto non esistente!")
			continue

		# incrementa/decrementa il saldo dell'altro conto corrente
		sbal = c2[0] - imp

		desc = input("Descrizione/causale: ") or None

		v_date = date.today()
		o_date = v_date + timedelta(days=3)
		# importo registrato in valore assoluto
		cursor.execute("INSERT INTO mov (ord, ben, imp, desc, v_date, o_date) VALUES (?, ?, ?, ?, ?, ?)", (o_iban, b_iban, abs(imp), desc, v_date, o_date))
		# aggiorna entrambi i conti
		cursor.execute("UPDATE customers SET bal = ? WHERE n_acc = ?", (pbal, cc,))
		cursor.execute("UPDATE customers SET bal = ? WHERE iban = ?", (sbal, s,))
		conn.commit()

except sqlite3.OperationalError as e:
	print(e)

