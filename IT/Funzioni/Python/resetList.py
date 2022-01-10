# file resetList.py

from __future__ import print_function

def resetList(li):
	for index in range(0, len(li)):
		li[index] = 0

li = [1, 2, 3]

print(li)

resetList(li)

print(li)

