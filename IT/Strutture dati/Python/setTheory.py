# file setTheory.py

from __future__ import print_function

# dichiara due insiemi di numeri interi

a = {0, 1, 2}
b = {2, 3, 4}

print("A =", a)
print("B =", b)

# unione di A e B

print("A u B =", a | b)

# intersezione di A e B

print("A & B =", a & b)

# differenza tra A e B

print("A - B =", a - b)

# ...e differenza tra B e A

print("B - A =", b - a)

# differenza simmetrica tra A e B

print("A ^ B =", a ^ b)

