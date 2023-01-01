# file esercizio17.py

from __future__ import print_function, division

rect = lambda b, h : b * h

def triangle(b, h, f):
	return f(b, h) / 2

b = 1
h = 1
while (h <= 10):
	print("Area del triangolo di base {} e altezza {} = {} cm quadrati.".format(b, h, triangle(b, h, rect)))
	b += 2
	h += 1

