# file esercizio10.py

from __future__ import print_function, division

def divide(a, b):
	return a / b if b is not 0 else float('nan')

a = 10
b = 3
c = 0

print("{} / {} = {:.3f}".format(a, b, divide(a, b)))
print("{} / {} = {}".format(a, c, divide(a, c)))

