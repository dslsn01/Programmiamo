# file esercizio29.py

from __future__ import print_function
from random import randint, randrange
from sys import exit
from os import linesep

l = randrange(5, 100+1, 5)
nums = [randint(1, 100) for n in range(l)]

print(nums)

nums.sort()

print(nums)

md = 1
counts = [0] * len(nums)
i = 0

while i < len(nums):
	n = nums[i]
	j = i+1 # indice dell'elemento successivo
	occ = 1
	while j < len(nums) and n == nums[j]:
		occ += 1
		j += 1
	counts[i] = occ # memorizza il numero di occorrenze
	if occ > md: md = occ
	i += occ # salta al prossimo numero

if md == 1:
	print("La lista non ha una moda.")
	exit()

print("Moda ({} occorrenze): ".format(md), end="")

j = 0
for i in range(0, len(counts)):
	if counts[i] == md:
		if j > 0: print(", ", end="")
		print(nums[i], end="")
		j += 1

print(".")

