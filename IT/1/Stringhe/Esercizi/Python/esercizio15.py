# file esercizio15.py

from __future__ import print_function, unicode_literals
from sys import stdin, version_info
if hasattr(__builtins__, 'raw_input'): input = raw_input

s = input("Scrivi una parola (o una frase): ")
if version_info[0] < 3: s = s.decode(stdin.encoding)

if not s:
	print("Stringa vuota!")
	exit()

# converte la parola o la frase in caratteri maiuscoli

print(s.upper())
