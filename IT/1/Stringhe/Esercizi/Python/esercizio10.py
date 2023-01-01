# file esercizio10.py
# -*- coding: utf-8 -*-

from __future__ import print_function

s = "Era pacifica pare"

s1 = s.replace(' ', '').lower()
l = len(s1)

o1 = l / 2
o2 = o1

if l % 2 != 0:
	o1 = l // 2
	o2 = o1+1

t1 = s1[:o1]
t2 = s1[o2:]

if t1 == t2[::-1]:
	print("La frase \"{}\" è palindroma.".format(s))

