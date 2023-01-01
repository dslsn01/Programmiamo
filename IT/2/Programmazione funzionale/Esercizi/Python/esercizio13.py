# file esercizio13.py

from __future__ import print_function
from sys import version_info

if version_info[0] > 2: from functools import reduce

li = [n for n in range(1, 100+1)]

tot = reduce(lambda a, b : a + b, li)

print(li)
print("Somma dei numeri in lista: {}".format(tot))

