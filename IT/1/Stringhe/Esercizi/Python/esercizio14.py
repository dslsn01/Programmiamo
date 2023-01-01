# file esercizio14.py

from __future__ import print_function, unicode_literals
from sys import stdin, version_info
import re
if hasattr(__builtins__, 'raw_input'): input = raw_input

s = input("Scrivi una frase e leggi le singole parole: ")
if version_info[0] < 3: s = s.decode(stdin.encoding)

if not s:
	print("Stringa vuota!")
	exit()

parts = filter(None, re.compile(r"[\s\.,?!]+").split(s))

for w in parts:
	print(w)
