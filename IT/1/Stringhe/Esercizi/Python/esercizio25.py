# file esercizio25.py

from __future__ import print_function, unicode_literals
import re
if hasattr(__builtins__, 'raw_input'): input = raw_input

cod = ""
pattern = re.compile(r"[A-Z]{6}[\d]{2}[ABCDEHLMPRST]{1}(?:0[1-9]|[1-6][\d]|7[01])[A-Z0-9]{4}[A-Z]{1}$")

while not cod:
	s = input("Digita il tuo codice fiscale: ")
	if pattern.match(s):
		cod = s
		print("Codice fiscale corretto.")
	else:
		print("Codice fiscale non valido!")

