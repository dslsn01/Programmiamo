# file esercizio30.py

from __future__ import print_function, division
from random import randint

def merge(l, r):
	if not l or not r: return l + r
	if l[0] > r[0]:
		return [r[0]] + merge(l, r[1:])
	else:
		return[l[0]] + merge(l[1:], r)

def mergesort(li):
	if len(li) <= 1: return li
	mid = len(li) // 2
	l = mergesort(li[:mid])
	r = mergesort(li[mid:])
	return merge(l, r)

li = [randint(1, 100) for n in range(25)]
li2 = mergesort(li)

print(li)
print(li2)

