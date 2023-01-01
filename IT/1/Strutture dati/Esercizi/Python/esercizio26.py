# file esercizio26.py

from __future__ import print_function
from random import randint

nums = [randint(1, 10) for i in range(10)]

print("Lista originale:\n{}".format(nums))

# ordina la lista

uniques = sorted(nums)

i = 0
while i < len(uniques):
	n = uniques[i]
	j = i+1
	while j < len(uniques) and n == uniques[j]:
		del uniques[j]
	i += 1

print("Lista senza elementi duplicati:\n{}".format(uniques))

