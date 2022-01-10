# file esercizio14.py
# -*- coding: utf-8 -*-

from __future__ import print_function
if hasattr(__builtins__, 'raw_input'): input = raw_input

s = input("Scrivi una parola o numero: ")

try:
	n = int(s)
	print(s, "è un numero intero.")

except ValueError as e1:
	print(e1)
	try:
		f = float(s)
		print(s, "è un numero in virgola mobile.")

	except ValueError as e2:
		print(e2)
		print("\"{}\" non può essere convertito in un numero.".format(s))

