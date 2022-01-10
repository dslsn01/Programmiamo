# file esercizio16.py

from __future__ import print_function
import itertools
from sys import version_info

if version_info[0] > 2: from functools import reduce

l1 = [1, 2, 3, 4]
l2 = [5, 6, 7]
l3 = [8, 9]
l4 = [10]

li = [l1, l2, l3, l4]

flat = reduce(list.__add__, li)

print(li)
print(flat)

