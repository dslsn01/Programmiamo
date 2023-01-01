# file esercizio4.py

from __future__ import print_function, division

a = 5
b = 10

print("a = {}, b = {}".format(a, b))

s = a + b

print("{} + {} = {}".format(a, b, s))

d = a - b

if d < 0:
	print("Differenza negativa!")

print("{} - {} = {}".format(a, b, d))

if d is not b-a:
	print("Sottrazione non commutativa. Scambio gli operandi.")
	d = b - a
	print("{} - {} = {}".format(b, a, d))

p = a * b

print("{} * {} = {}".format(a, b, p))

q = a / b

print("{} / {} = {}".format(a, b, q))

if q is not b/a:
	print("Divisione non commutativa. Scambio gli operandi.")
	q = b / a
	print("{} / {} = {}".format(b, a, q))

