# file esercizio5.py

from __future__ import print_function
from random import randint
from collections import OrderedDict

li = [randint(1, 10) for n in range(10)]
print(li)

u = list(OrderedDict.fromkeys(li))
print(u)

