# file esercizio40.py

from __future__ import print_function

nums = {1 : 7, 2 : 5, 3 : 3}

print("Numeri =", nums)

maxKey = max(nums)
minKey = min(nums)

print("Chiave maggiore nel dizionario: {}, associata al valore {}.".format(maxKey, nums[maxKey]))
print("Chiave minore nel dizionario: {}, associata al valore {}.".format(minKey, nums[minKey]))
