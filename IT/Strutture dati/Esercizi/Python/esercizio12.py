# file esercizio12.py

from __future__ import print_function
from random import randint

nums = [randint(1, 100) for n in range(10)]

print(nums)

m = nums[0]

for i in range(1, len(nums)):
	n = nums[i]
	if n > m:
		m = n

print("Numero maggiore in lista:", m)

