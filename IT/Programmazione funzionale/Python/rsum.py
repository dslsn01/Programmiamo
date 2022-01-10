# file rsum.py

from __future__ import print_function

def rsum(n):
	if n in (0, 1): return n
	else:
		return n + rsum(n - 1)

print("Somma dei numeri da 1 a 100 = {}".format(rsum(100)))

