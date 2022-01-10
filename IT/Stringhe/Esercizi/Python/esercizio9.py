# file esercizio9.py
# -*- coding: utf-8 -*-

from __future__ import print_function, unicode_literals

import os

s = "prìncipi"
ss = ("Prìncipi", "princìpi")

def strEq(s1, s2):
	l = len(s1)
	if l != len(s2): return False

	for i in range(l):
		c = s1[i]
		c2 = s2[i]

		if c != c2 and c.lower() != c2.lower():
			return False
	return True

for t in ss:
	if strEq(s, t):
		print("Le parole \"{}\" e \"{}\" sono uguali.".format(s, t))
	else:
		print("Le parole \"{}\" e \"{}\" sono diverse.".format(s, t))

