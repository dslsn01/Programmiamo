# file esercizio18.py

from __future__ import print_function, division
from random import randint, randrange

def mdn(li):
	li = sorted(li)
	i = len(li)//2
	if len(li) % 2 != 0:
		return li[i]
	else:
		return (li[i-1] + li[i]) / 2

l = randrange(5, 100+1, 5)
li = [randint(1, 100) for n in range(l)]

m = mdn(li)

print(li)
print("Mediana: {}".format(m))

