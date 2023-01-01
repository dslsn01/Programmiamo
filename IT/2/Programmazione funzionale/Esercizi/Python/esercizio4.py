# file esercizio4.py

from __future__ import print_function
from random import randint

li = [randint(1, 100) for n in range(10)]

l2 = sorted(li)
l3 = sorted(li, reverse=True)

print(li)
print(l2)
print(l3)

