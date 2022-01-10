# file esercizio29.py

from __future__ import print_function

def fsqr(n, g):
	if abs(g*g - n) <= 0.0001: return g
	mid = (g + n/g)/2.0
	return fsqr(n, mid)

nums = [2, 5, 7, 9, 16, 32, 64, 81]

for n in nums:
	print("sqrt({}) = {:.3f}".format(n, fsqr(n, n/2)))

