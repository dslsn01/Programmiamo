# file esercizio31.py
# -*- coding: utf-8 -*-

from __future__ import print_function, division

if hasattr(__builtins__, 'raw_input'): input = raw_input

l = input("Quanti numeri vuoi inserire? ")

if not l.isdigit():
	print("Numero non valido!")
	exit()

limit = int(l)

i = 0
tot = 0

while i < limit:
	s = input("Numero corrente: ")

	if not s.replace("-", "").isdigit():
		print("Numero non valido!")
		continue

	n = int(s)

	tot += n

	i += 1

print("La media di tutti i numeri è {}.".format(tot / limit))

