# file esercizio20.py

from __future__ import print_function, division

def avg(li):
	return sum(li) / len(li)

print("Media tra 1, 7, 13 = {}".format(avg([1, 7, 13])))
print("Media tra 4, 9, 17, 33, 39 = {}".format(avg([4, 9, 17, 33, 39])))

