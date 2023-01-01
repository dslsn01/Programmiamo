# file testSets.py
# -*- coding: utf-8 -*-

from __future__ import print_function
from sys import stdout
from os import linesep

# dichiara un set di numeri interi: i numeri sono aggiunti in ordine casuale, ma il set li riordina automaticamente secondo l'ordinamento naturale

n = {2, 0, 1}
print(n)

# verifica la presenza dello zero nel set

if 0 in n:
	print("L'insieme N include lo zero.")

# aggiunge il numero 3 al set

n.add(3)

# scorre tutti gli elementi dell'insieme con un ciclo for

for m in n:
	print(m, end=" ")

stdout.write(linesep)

# aggiunge i numeri 4, 5, 6, 7 al set

n.update([5, 4, 7, 6])
print(n)

# recupera il primo elemento (lo zero) dal set

p = n.pop()
print("Primo elemento di N:", p)

# cancella il numero 7 dal set

n.remove(7)
print(n)

# cancella tutti gli elementi del set

n.clear()
print("Cardinalità dell'insieme vuoto:", len(n))
print(n)

