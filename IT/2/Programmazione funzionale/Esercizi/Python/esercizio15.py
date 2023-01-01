# file esercizio15.py

from __future__ import print_function
from sys import version_info

if version_info[0] > 2: from functools import reduce

li = [n for n in range(1, 10+1)]

s = reduce(lambda s1, s2: "{}, {}".format(s1, s2), li)

print(s)

