# file esercizio8.py

from __future__ import print_function, division

nums = [1, 3, 5, 7, 9]

print(nums)

tot = 0

for n in nums:
	tot += n

print("Media matematica degli elementi:", tot / len(nums))

