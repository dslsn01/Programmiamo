# file esercizio1.py

from __future__ import print_function
from random import randint

def f(a, b, c):
	if a > b:
		return a if a > c else c
	else:
		return b if b > c else c

a = randint(1, 10)
b = randint(1, 10)
c = randint(1, 10)

print("a={}, b={}, c={}".format(a, b, c))
print("Numero maggiore: {}".format(f(a, b, c)))

