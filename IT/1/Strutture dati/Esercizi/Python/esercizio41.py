# file esercizio41.py

from __future__ import print_function

nums = {1 : 7, 2 : 5, 3 : 3}

print("Numeri =", nums)

maxKey = max(nums, key=nums.get)
minKey = min(nums, key=nums.get)

print("Maggior valore nel dizionario: {}, associato alla chiave {}.".format(nums[maxKey], maxKey))
print("Minor valore nel dizionario: {}, associato alla chiave {}.".format(nums[minKey], minKey))

