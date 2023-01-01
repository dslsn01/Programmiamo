# file esercizio30.py
# -*- coding: utf-8 -*-

from __future__ import print_function

if hasattr(__builtins__, 'raw_input'): input = raw_input

l = input("Quanti numeri vuoi inserire? ")

if not l.isdigit():
	print("Numero non valido!")
	exit()

limit = int(l)

i = 0
x = 0

while i < limit:
	s = input("Numero corrente: ")

	if not s.replace("-", "").isdigit():
		print("Numero non valido!")
		continue

	n = int(s)

	if x == 0 or n < x:
		x = n

	i += 1

print("Il numero più piccolo è {}.".format(x))

