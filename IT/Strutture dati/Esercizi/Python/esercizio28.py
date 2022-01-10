# file esercizio28.py

from __future__ import print_function, division
from random import randint, randrange
from sys import stdout
from os import linesep

l = randrange(5, 100+1, 5)
nums = [randint(1, 100) for n in range(l)]

print(nums)

nums.sort()

print(nums)

n = len(nums)

mdn = 0

if n % 2 != 0:
	i = n // 2
	mdn = nums[i]
else:
	i = n // 2
	j = i-1
	mdn = (nums[i] + nums[j])/2

print("Mediana: {}.".format(mdn))

