# file esercizio12.py

from __future__ import print_function 

def isum(n):
	tot = 0
	for i in range(1, n+1):
		tot += i
	return tot

print("Somma dei numeri da 1 a 100 = {}".format(isum(100)))

