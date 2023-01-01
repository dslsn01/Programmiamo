# file esercizio35.py

from __future__ import print_function

a = {0, 1, 2}
b = {3, 4, 5}
c = {2, 3, 4}

print("A =", a)
print("B =", b)
print("C =", c)

if a.isdisjoint(b):
	print("Gli insiemi A e B sono disgiunti!")

if not a.isdisjoint(c):
	print("Gli insiemi A e C hanno elementi comuni:", a & c)

