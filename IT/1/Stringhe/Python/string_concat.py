# file string_concat.py
# -*- coding: utf-8 -*-

from __future__ import print_function, unicode_literals

hello = "Ciao, "
world = "mondo!"

# concatena le due stringhe, usando l'operatore "+" 

s1 = hello + world

print(s1)

# ...o il metodo join(), che riceve una lista di stringe

s2 = "".join([hello, world])

print(s2)

# confronta le due stringhe con l'operatore "=="

if s1 == s2:
	print("Le stringhe \"{}\" e \"{}\" sono uguali.".format(s1, s2))

n = 1

# concatena le due stringhe: converte il numero 1 in stringa con la funzione str()

print(str(n) + " è un numero positivo.")

# ...o con l'operatore modulo, 

print("%d è un numero positivo." % n)

# ...o con il metodo format().

print("{} è un numero positivo.".format(n))

