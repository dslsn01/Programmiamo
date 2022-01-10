# file esercizio24.py
# -*- coding: utf-8 -*-

from __future__ import print_function, unicode_literals
from sys import stdin, version_info
import re
if hasattr(__builtins__, 'raw_input'): input = raw_input

print("********************* Cambia la password *********************")
print("La password deve contenere un minimo di otto caratteri, inclusa una maiuscola, un numero e un simbolo speciale.")

pwd = ""
pattern = re.compile(u"^(.{0,7}|[^\\d]*|[^a-zà-ù]*|[^A-ZÀ-Ù]*|[a-zA-ZÀ-ù0-9]*)$")

while not pwd:
	s = input("Digita la nuova password: ")
	if version_info[0] < 3: s = s.decode("utf-8")
	if not pattern.match(s):
		pwd = s
		print("Nuova password salvata.")
	else:
		print("Password non valida!")

