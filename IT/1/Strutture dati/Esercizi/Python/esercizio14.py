# file esercizio14.py

from __future__ import print_function
from random import randint

nums = [randint(1, 100) for n in range(10)]

print(nums)

nums.sort()

print(nums)

maxIndex = len(nums)-1
print("Numero maggiore in lista:", nums[maxIndex])

minIndex = 0
print("Numero minore in lista:", nums[minIndex])

