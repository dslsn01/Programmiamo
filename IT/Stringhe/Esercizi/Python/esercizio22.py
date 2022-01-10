# file esercizio22.py
# -*- coding: utf-8 -*-

from __future__ import print_function, unicode_literals
from re import finditer
from os import linesep

s = "Nome: \"John\", cognome: \"Doe\", età: 32, indirizzo: \"ignoto\" numero di telefono: 333-1234567" + linesep
s += "Nome: \"Paula\", cognome: \"Poe\", età: 30, numero di telefono: 320/1200100" + linesep
s += "Nome: \"Joe\", cognome: \"Bloggs\", età: 35, numero di telefono: 02-987654" + linesep
s += "Nome: \"Jane\", cognome: \"Doe\", indirizzo: \"?\" numero di telefono: 06/12345001"

print(s)
print("Numeri di telefono: ")

regex = r"[\d]{2,3}[-/]{1}[\d]{5,8}"

for match in finditer(regex, s):
	print(match.group())

