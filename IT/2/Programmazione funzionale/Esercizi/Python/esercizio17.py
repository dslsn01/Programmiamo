# file esercizio17.py

from __future__ import print_function, division
from random import randint
from sys import version_info

if version_info[0] > 2: from functools import reduce

def avg(li):
	return reduce(lambda a, b : a + b, li) / len(li)

li = [randint(1, 100) for n in range(25)]

m = avg(li)

print(li)
print("Media: {}".format(m))

