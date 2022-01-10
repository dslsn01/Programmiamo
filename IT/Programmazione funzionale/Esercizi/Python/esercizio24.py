# file esercizio24.py

from __future__ import print_function, division
from functools import partial

f = lambda a, b: a * b

print("3 x 3 = {}".format(f(3, 3)))

g = partial(f, 1)

print("id(3) = {}".format(g(3)))

h = lambda a, b : a / b

print("3 / 2 = {}".format(h(3, 2)))

# calcola l'elemento inverso

i = partial(h, 1)

print("Inverso moltiplicativo di 3 = {:.6f}".format(i(3)))

