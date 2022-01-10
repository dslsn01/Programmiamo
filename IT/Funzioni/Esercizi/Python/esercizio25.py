# file esercizio24.py

from __future__ import print_function

def mcd(m, n):
	if n == 0: return 0
	r = m % n
	if r == 0: return n
	else:
		return mcd(n, r)

def mcm(m, n):
	return (m * n) / mcd(m, n)

print("mcm({}, {}) = {}".format(640, 480, mcm(640, 480)))
print("mcm({}, {}) = {}".format(1024, 768, mcd(1024, 768)))
print("mcm({}, {}) = {}".format(4096, 2048, mcd(4096, 2048)))

