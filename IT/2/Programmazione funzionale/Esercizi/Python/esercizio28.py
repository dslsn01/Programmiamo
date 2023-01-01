# file esercizio28.py

from __future__ import print_function

def rsum(li):
	if not li: return 0
	else:
		return li[0] + rsum(li[1:])

li = list(range(1, 100+1))

print("Somma dei numeri da 1 a 100 = {}".format(rsum(li)))

