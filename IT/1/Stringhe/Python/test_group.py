# file test_group.py
# -*- coding: utf-8 -*-

from __future__ import print_function, unicode_literals
from re import finditer
from sys import stdout
from os import linesep

s = "Via Roma 40, Milano, MI"
regex = r"([\w\s]+),\s([\w]+),\s([\w]{2})"

for match in finditer(regex, s):
	print("Stringa completa: {}".format(match.group()))
	print("Indirizzo: {}".format(match.group(1)))
	print("Città: {}".format(match.group(2)))
	print("Provincia: {}".format(match.group(3)))

stdout.write(linesep)

s = "Nome: \"John\", cognome: \"Doe\", età: \"30\", indirizzo: \"ignoto\" segni particolari: \"\""
print(s)

regex = r"(['\"]).*?\1"

for match in finditer(regex, s):
	print(match.group())

