# file testTuple.py
# -*- coding: utf-8 -*-

from __future__ import print_function

# dichiara una tupla di interi

tu1 = (1, 3, 5, 7, 9)
print(tu1)

# verifica la presenza dell'elemento 1 nella tupla

if 1 in tu1:
	index = tu1.index(1)
	print("Nella tupla c'è il numero 1 alla posizione {}.".format(index))

# slicing di tuple

sect1 = tu1[3:]
sect2 = tu1[:3]
sect3 = tu1[1:4]

print(sect1)
print(sect2)
print(sect3)

# dichiara una seconda tupla di interi

tu2 = (11, 13, 17, 19, 23)

for i in range(len(tu2)):
	print("{}) {}".format(i, tu2[i]))

# concatenazione le due tuple

tu3 = tu1 + tu2
print(tu3)

