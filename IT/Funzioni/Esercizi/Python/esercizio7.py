# file esercizio7.py

from __future__ import print_function

def maximum(a, b):
	return a if a > b else b

a = 5
b = 10
c = 15

print("Massimo tra {} e {}: {}".format(a, b, maximum(a, b)))
print("Massimo tra {} e {}: {}".format(b, c, maximum(b, c)))

