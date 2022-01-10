# file test_number.py
# -*- coding: utf-8 -*-

from __future__ import print_function, unicode_literals
from re import match

# rinomina 'raw_input()' in 'input()' per compatibilità con Python 3
if hasattr(__builtins__, 'raw_input'): input = raw_input

s = input("Digita un numero intero o in virgola mobile: ")

# controlla con due regex se "s" sia un numero intero/decimale

if match(r"^[0-9]+$", s):
	print("{} è un numero intero.".format(s))

elif match(r"^[0-9]+\.[0-9]{1,}$", s):
	print("{} è un numero in virgola mobile.".format(s))

else:
	print("Attenzione! \"{}\" non è un numero!".format(s))

