# file esercizio5.py

from __future__ import print_function

nums = ["1", "2", "", "3", "abc", "7", "def"]
print(nums)

tot = 0

for n in nums:
	try:
		tot += int(n)
	except ValueError as e:
		print(e)

print("Somma dei numeri presenti: {}".format(tot))
print("Fine del programma.")

