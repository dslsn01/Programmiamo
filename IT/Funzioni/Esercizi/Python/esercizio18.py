# file esercizio18.py
# -*- coding: utf-8 -*-

from __future__ import print_function, division
from random import randint

def recp(n):
	if n == 0: return float('nan')
	return 1/n

for i in range(5):
	r = randint(2, 15)
	print("Il reciproco di {} è {:.3f}.".format(r, recp(r)))

