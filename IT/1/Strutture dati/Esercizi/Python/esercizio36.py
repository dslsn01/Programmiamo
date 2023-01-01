# file esercizio36.py
# -*- coding: utf-8 -*-

from __future__ import print_function

a = {0, 1, 2, 3, 4}
b = {1, 2, 3}

print("A =", a)
print("B =", b)

# se tutti gli elementi di B sono anche elementi di A, allora B è un sottoinsieme di A

if b < a:
	print("L'insieme B è un sottoinsieme di A!")

