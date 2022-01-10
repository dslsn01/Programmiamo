# file esercizio28.py
# -*- coding: utf-8 -*-

from __future__ import print_function

if hasattr(__builtins__, 'raw_input'): input = raw_input

i = 0
x = 0

while i < 10:
	s = input("Numero corrente: ")

	if not s.replace("-", "").isdigit():
		print("Numero non valido!")
		continue

	n = int(s)

	if n > x:
		x = n

	i += 1

print("Il numero più grande è {}.".format(x))

