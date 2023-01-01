# file esercizio25.py

from __future__ import print_function, division
from functools import partial

f = lambda a, b: a + b

print("3 + 3 = {}".format(f(3, 3)))

g = partial(f, 0)

print("id(3) = {}".format(g(3)))

h = lambda a, b : a - b

print("3 - 2 = {}".format(h(3, 2)))

# calcola l'elemento inverso

i = partial(h, 0)

print("Inverso additivo di 3 = {}".format(i(3)))

