# file esercizio37.py
# -*- coding: utf-8 -*-

from __future__ import print_function

a = {1, 2, 3}
b = {3, 4, 5}
c = {-1, 0, 1}

print("A =", a)
print("B =", b)
print("C =", c)

a.difference_update(b)

print("Differenza tra A e B:", a)
print("Differenza tra (A - B) e C:", a - c)

