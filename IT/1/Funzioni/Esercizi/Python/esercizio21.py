# file esercizio21.py

from __future__ import print_function

def square(li):
	for i in range(len(li)):
		li[i] *= li[i]

li = [n for n in range(1, 10+1)]

print("Lista originale:\n{}".format(li))

square(li)

print("Lista (elementi al quadrato):\n{}".format(li))

