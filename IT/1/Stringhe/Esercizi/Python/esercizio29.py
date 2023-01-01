# file esercizio29.py
# -*- coding: utf-8 -*-

from __future__ import print_function, unicode_literals
from sys import stdin, stdout, version_info
from re import match, sub
if hasattr(__builtins__, 'raw_input'): input = raw_input

s = input("Scrivi una parola (o una frase): ")
if version_info[0] < 3: s = s.decode(stdin.encoding)

if not s:
	print("Stringa vuota!")
	exit()

s1 = sub("[^a-zA-ZÀ-ù]", "", s)

if not s1:
	print("La stringa \"{}\" non contiene caratteri alfabetici!".format(s))
	exit()

stdout.write("Controllando i caratteri: ")

if s1.isupper():
	print("   -> la stringa \"{}\" contiene solo caratteri maiuscoli.".format(s))
elif s1.islower():
	print("   -> la stringa \"{}\" contiene solo caratteri minuscoli.".format(s))
else:
	print("   -> la stringa \"{}\" contiene caratteri maiuscoli e minuscoli.".format(s))

stdout.write("Con le espressioni regolari: ")

# tutti i caratteri che non sono a-z (minuscoli)

if match("^[^a-zà-ù]+$", s1):
	print("-> la stringa \"{}\" contiene solo caratteri maiuscoli.".format(s))

# tutti i caratteri che non sono A-Z (maiuscoli)

elif match("^[^A-ZÀ-Ù]+$", s1):
	print("-> la stringa \"{}\" contiene solo caratteri minuscoli.".format(s))

# caratteri misti
else:
	print("-> la stringa \"{}\" contiene caratteri maiuscoli e minuscoli.".format(s))

