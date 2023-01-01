# file esercizio25.py

from __future__ import print_function
from random import randint

nums = [randint(1, 10) for i in range(10)]

print("Lista originale:\n{}".format(nums))

l = len(nums)
dupl = [False] * l

d = 0

for i in range(l):
	for j in range(i+1, l):
		if nums[i] == nums[j] and not dupl[j]:
			dupl[j] = True
			d += 1

uniques = []
for i in range(l):
	if dupl[i] == False:
		uniques.append(nums[i])

print("Lista senza elementi duplicati:\n{}".format(uniques))

