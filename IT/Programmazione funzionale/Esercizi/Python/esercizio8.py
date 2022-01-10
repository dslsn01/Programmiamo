# file esercizio8.py

from __future__ import print_function

def npow(k, li):
	return list(map(lambda k, p : k**p, [k for n in range(len(li))], li))

li = [n for n in range(1, 10+1)]

print(li)

p = npow(2, li)

print(p)

