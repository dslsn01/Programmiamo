# file esercizio1.py

from __future__ import print_function

def id(x):
	return x

for i in range(1, 4):
	print("id({}) = {}".format(i, id(i)))

