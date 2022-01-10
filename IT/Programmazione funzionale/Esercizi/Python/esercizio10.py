# file esercizio10.py

from __future__ import print_function

e = list(filter(lambda n : n % 2 == 0, [n for n in range(1, 100+1)]))

print(e)

