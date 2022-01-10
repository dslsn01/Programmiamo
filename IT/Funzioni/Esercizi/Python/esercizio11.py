# file esercizio11.py
# -*- coding: utf-8 -*-

from __future__ import print_function

def multiple(a, b):
	if a == 0 or b == 0: return False
	return b % a == 0 if a <= b else a % b == 0

a = 5
b = 10
c = 11

print("{} è multiplo di {}? {}".format(b, a, multiple(a, b)))
print("{} è multiplo di {}? {}".format(c, a, multiple(c, a)))

