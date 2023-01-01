# file esercizio27.py

from __future__ import print_function
from random import randint
from sys import stdout
from os import linesep

nums = [randint(0, 99) for n in range(100)]

print(nums)

counts = [0] * len(nums)
md = 1

for i in range(0, len(nums)):
	c = nums[i]
	counts[c] += 1
	if counts[c] > md:
		md = counts[c]

if md == 1:
	print("La lista non ha una moda.")
	exit()

print("Moda ({} occorrenze): ".format(md), end="")

j = 0
for i in range(0, len(counts)):
	if counts[i] == md:
		if j > 0: print(", ", end="")
		print(i, end="")
		j += 1

print(".")

