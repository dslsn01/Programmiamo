# file esercizio5.py

from __future__ import print_function

nums = [1, 3, 5, 7, 9]

for i in range(len(nums)-1, -1, -1):
	print("{}) {}".format(i, nums[i]))

