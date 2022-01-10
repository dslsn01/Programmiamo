# file esercizio14.py

from __future__ import print_function
from sys import version_info

if version_info[0] > 2: from functools import reduce

li = ["Nel", "bel", "mezzo", "del", "cammin", "di", "nostra", "vita"]

s = reduce(lambda t1, t2 : "{} {}".format(t1, t2), li)

print(li)
print("\"{}\"".format(s))

