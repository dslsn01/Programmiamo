# file esercizio2.py

from __future__ import print_function
from sys import stdout
from os import linesep

nums = [1, 3, 5, 7, 9]

i = 0

while i < len(nums):
	print(nums[i], end=" ")
	i += 1

stdout.write(linesep)

