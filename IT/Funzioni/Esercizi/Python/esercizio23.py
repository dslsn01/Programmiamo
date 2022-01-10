# file esercizio23.py

from __future__ import print_function

def mcd(m, n):
	if n == 0: return 0
	r = 0
	while n != 0:
		r = m % n
		m = n
		n = r
	return m

print("MCD({}, {}) = {}".format(24, 36, mcd(24, 36)))
print("MCD({}, {}) = {}".format(42, 56, mcd(42, 56)))
print("MCD({}, {}) = {}".format(54, 72, mcd(54, 72)))

