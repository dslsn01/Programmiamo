# file esercizio26.py

from __future__ import print_function
from random import randint
from functools import partial

def f(a, b, c):
	if a > b:
		return a if a > c else c
	else:
		return b if b > c else c

# funzione che implementa il currying

def g(a):
	def h(b):
		def i(c):
			if a > b:
				return a if a > c else c
			else:
				return b if b > c else c
		return i
	return h

a = randint(1, 10)
b = randint(1, 10)
c = randint(1, 10)

print("a={}, b={}, c={}".format(a, b, c))

# calcola il numero maggiore con l'applicazione parziale della funzione originale

print("Trovo il maggiore con l'applicazione parziale: ")

h = partial(f, a) # h = f(a, ...)
m = h(b, c)

print("Numero maggiore: {}".format(m))

i = partial(h, b) # i = f(a, b, ...)
m = i(c)

print("Numero maggiore: {}".format(m))

print("Trovo il maggiore con il currying: ")

# chiamata di funzione con il currying

m = g(a)(b)(c)

print("Numero maggiore: {}".format(m))

