# file esercizio22.py

from __future__ import print_function

def swap(li):
	j = len(li)-1
	for i in range(len(li) // 2):
		z = li[j]
		li[j] = li[i]
		li[i] = z
		j -= 1

li = [n for n in range(1, 10+1)]

print("Lista originale:\n{}".format(li))

swap(li)

print("Lista (elementi invertiti):\n{}".format(li))

