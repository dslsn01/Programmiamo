# file esercizio3.py

from __future__ import print_function
from sys import stdout
from os import linesep

nums = [1, 3, 5, 7, 9]

i = len(nums) - 1

while i >= 0:
	print(nums[i], end=" ")
	i -= 1

stdout.write(linesep)

