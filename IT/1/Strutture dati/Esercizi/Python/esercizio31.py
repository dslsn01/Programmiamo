# file esercizio31.py

from __future__ import print_function
from random import randint

nums = [randint(1, 100) for i in range(10)]

print("lista originale:\n{}".format(nums))

n = len(nums) - 1
lc = n
while lc > 0:
	lc = 0
	for i in range(n):
		n1 = nums[i]
		n2 = nums[i+1]
		if n1 > n2:
			nums[i] = n2
			nums[i+1] = n1
		lc = i
	n = lc

print("lista ordinata:\n{}".format(nums))

