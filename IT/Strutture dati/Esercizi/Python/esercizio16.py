# file esercizio16.py

from __future__ import print_function

nums = [1, 3, 5, 7, 9]
val = 10

print(nums)

for i in range(len(nums)):
	for j in range(i+1, len(nums)):
		if nums[i] + nums[j] == val:
			print("{} + {} = {}".format(nums[i], nums[j], val))

