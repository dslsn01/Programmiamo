# file ifTest.py
# -*- coding: utf-8 -*-

from __future__ import print_function

if hasattr(__builtins__, 'raw_input'): input = raw_input

# legge da tastiera il numero intero digitato dall'utente 

s = input("Inserisci un intero: ")

if not s.isdigit():
	print("Numero non valido!")
	exit()

# converte la stringa in un numero intero

n = int(s)

# controlla se il numero digitato sia pari o dispari

if n % 2 == 0:
	print(n, "è pari!")
else:
	print(n, "è dispari!")

