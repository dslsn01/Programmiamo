# file esercizio11.py

from __future__ import print_function

nums = [1, 3, 5, 7, 9]

print(nums)

# inverte la lista originale

j = len(nums)-1
for i in range(len(nums) // 2):
	z = nums[j]
	nums[j] = nums[i]
	nums[i] = z
	j -= 1

print(nums)

