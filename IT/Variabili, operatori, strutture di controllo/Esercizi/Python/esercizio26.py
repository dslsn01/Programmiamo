# file esercizio26.py
# -*- coding: utf-8 -*-

from __future__ import print_function

if hasattr(__builtins__, 'raw_input'): input = raw_input

s = input("Scrivi un numero: ")

if not s.replace("-", "").isdigit():
	print("Numero non valido!")
	exit()

n = int(s)

if n > 0:
	print(n, "è positivo.")
else:
	print(n, "è uguale o minore di zero.")

