# file passByReference.py

from __future__ import print_function

def appendToList(li):
	li.append(4)

li = [1, 2, 3]

print(li)

appendToList(li)

print(li)

