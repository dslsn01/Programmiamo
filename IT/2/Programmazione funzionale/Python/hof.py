# file hof.py

from __future__ import print_function
from random import randint

nums = [randint(1, 100) for n in range(20)]

f = lambda n : (n % 2 == 0, n)

print(f)

s = sorted(nums, key=f)

print("Lista originale:")
print(nums)
print("Numeri pari a destra, dispari a sinistra:")
print(s)

