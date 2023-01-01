# file sorting.py

from __future__ import print_function
from random import randint
from operator import itemgetter

# dichiara una lista di interi casuali

li = [randint(1, 100) for i in range(10)]

print("Lista originale:")
print(li)

# ordina gli elementi della lista

li.sort()

print("Lista ordinata:")
print(li)

# crea una lista di tuple

li2 = [(7, 'K'), (5, 'M'), (3, 'B'), (1, 'R'), (6, 'Y'), (4, 'C'), (2, 'G')]

print("Lista di tuple originale:")
print(li2)

# crea una seconda lista con gli elementi della prima lista, ordinandoli per numero

li3 = sorted(li2, key=itemgetter(0))

print("Lista di tuple ordinate:")
print(li3)

