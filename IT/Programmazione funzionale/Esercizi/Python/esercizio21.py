# file esercizio21.py

from __future__ import print_function
import math

def compose(g, f):
	return lambda x : g(f(x))

f = lambda x : math.e**x
g = lambda y : y + 1

# funzione composta (g o f)(x) = e^x + 1

gof = compose(g, f)

print(gof)
print("e^3 + 1 = {:.2f}".format(gof(3)))

