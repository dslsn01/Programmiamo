# file esercizio16.py

from __future__ import print_function

def rect(b, h):
	return b * h

b = 1
h = 1

while (h <= 10):
	print("Area del rettangolo di base {} e altezza {} = {} cm quadrati.".format(b, h, rect(b, h)))
	b += 2
	h += 1

