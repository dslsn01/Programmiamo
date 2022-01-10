# file esercizio24.py

from __future__ import print_function
from random import randint

nums = [randint(1, 100) for n in range(20)]

print("Lista originale: ")
print(nums)

l = 0
r = len(nums)-1

for i in range(0, len(nums)):
	while nums[l] % 2 == 0: l += 1
	while nums[r] % 2 != 0: r -= 1
	if l < r:
		tmp = nums[i]
		nums[r] = nums[l]
		nums[l] = tmp

print("Lista originale, numeri pari a destra, dispari a sinistra: ")
print(nums)

p = nums[:l]  # numeri pari
dp = nums[l:] # numeri dispari

p.sort()
print("Numeri pari (ordinati): ")
print(p)

dp.sort()
print("Numeri dispari (ordinati): ")
print(dp)

