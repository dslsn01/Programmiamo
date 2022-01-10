# file esercizio5.py

from __future__ import print_function

def comp(a, b):
	return a > b

a = 5
b = 10

print("{} > {}? {}".format(a, b, comp(a, b)))
print("{} > {}? {}".format(b, a, comp(b, a)))

