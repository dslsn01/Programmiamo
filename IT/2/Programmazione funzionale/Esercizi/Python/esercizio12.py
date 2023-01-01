# file esercizio12.py

from __future__ import print_function

li = [n for n in range(1, 100+1)]

# trova tutti i numeri dispari che sono anche multipli di 3

m = list(filter(lambda n : n % 3 == 0, filter(lambda n : n % 2 == 1, li)))

print(m)

