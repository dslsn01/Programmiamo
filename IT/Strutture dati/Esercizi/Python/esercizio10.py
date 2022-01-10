# file esercizio10.py

from __future__ import print_function

nums = [1, 3, 5, 7, 9]

# crea una copia con la list comprehension
copy = [n for n in nums[::-1]]

print(nums)
print(copy)

