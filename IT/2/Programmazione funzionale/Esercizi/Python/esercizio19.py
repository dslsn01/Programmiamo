# file esercizio19.py

from __future__ import print_function
from itertools import groupby
from random import randint, randrange
from sys import version_info

if version_info[0] > 2: from functools import reduce

def mode(li):
	freq = [(key, len(list(grp))) for key, grp in groupby(sorted(li))]
	md = max(freq, key=lambda t : t[1])[1]
	return list(filter(lambda t : t[1] == md, freq))

l = randrange(5, 100+1, 5)
li = [randint(1, 100) for md in range(l)]

print(li)

# valori con relativa frequenza

fv = mode(li)

md = fv[0][1]

if md == 1:
	print("La lista non ha una moda.")
	exit()

# stampa la moda

print("Moda ({} occorrenze): ".format(md), end="")

if len(fv) == 1:
	print(fv[0][0])
else:
	lm = [t[0] for t in fv]
	print(reduce(lambda m1, m2: "{}, {}".format(m1, m2), lm))

