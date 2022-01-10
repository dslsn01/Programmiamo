# file esercizio30.py

from __future__ import print_function, unicode_literals
from sys import stdin
from os import linesep
import re
if hasattr(__builtins__, 'raw_input'): input = raw_input

print("Programmiamo un client di posta elettronica.")

# destinatario
dest = ""

# oggetto
obj = ""

# corpo della mail
body = ""

# eventuale allegato
att = ""

exit = False

print("From: joebloggs@programmiamo.com")

mailPattern = re.compile(r"[\w\.]+@[\w]+\.[\w]{2,}")
attPattern = re.compile(r"alleg(at)?o")

while not exit:
	if not dest:
		_dest = input("To: ")
		if not mailPattern.match(_dest): continue
		dest = _dest

	if not obj:
		_obj = input("Oggetto: ")
		obj = _obj if _obj else " "

	if not body:
		print("------- Messaggio -------" + linesep)
		text = stdin.readlines()
		if len(text) > 0:
			text = [s.decode(stdin.encoding) for s in text]
			for line in text:
				body += line
		else:
			body = " "

		print(linesep + "-------------------------")

	buf1 = input("\"y\" - invia la mail" + linesep + "\"a\" - aggiungi un allegato" + linesep + "\"q\" - esci" + linesep)
	opt = '\0' if not buf1 else buf1

	if opt.lower() == "y":
		if not att:
			if attPattern.search(obj) or attPattern.search(body):
				print("Forse vuoi allegare qualcosa. Inviare?")
				buf2 = input("\"s\" - invia senza allegati" + linesep + "\"n\" - torna alla mail" + linesep)
				c = '\0' if not buf2 else buf2
				if c != 's': continue

		print("Messaggio inviato.")

	elif opt.lower() == "a":
		_att = input("File da allegare: ")
		if not _att: continue
		att = _att
		print("Caricamento di \"{}\"...".format(att))
		print("####### 100% completato #######")
		continue

	exit = True

