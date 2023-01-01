# file lambda.py

from __future__ import print_function

# dichiara una funzione lambda (anonima)
f = lambda n : n * n

n = 3
square = f(n)

print("{} al quadrato = {}".format(n, square))

