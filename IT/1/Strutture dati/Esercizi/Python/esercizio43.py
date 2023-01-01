# file esercizio43.py

from __future__ import print_function
if hasattr(__builtins__, 'raw_input'): input = raw_input

from sys import exit

messages = {"it" : "Benvenuto!", "en" : "Welcome!", "en-us" : "Welcome!"}

lang = input("Seleziona la tua lingua: ")

if lang in messages:
	print(messages[lang])
else:
	if not lang:
		print(messages["en"])
		exit()

	s = input("Lingua sconosciuta!\nAggiungere nuova lingua? s/n: ").lower()

	if s.lower() == "s":
		msg = input("Nuovo messaggio di benvenuto: ")
		messages[lang] = msg

		print(messages[lang])
		print("Messaggi di benvenuto aggiornati.")

		for k in messages.keys():
			print("{}: {}".format(k, messages[k]))

