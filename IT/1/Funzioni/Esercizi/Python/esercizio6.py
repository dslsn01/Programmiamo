# file esercizio6.py
# -*- coding: utf-8 -*-

from __future__ import print_function

def even(n):
	return True if n % 2 == 0 else False

a = 2
b = 3

print("{} è pari? {}".format(a, even(a)))
print("{} è pari? {}".format(b, even(b)))

