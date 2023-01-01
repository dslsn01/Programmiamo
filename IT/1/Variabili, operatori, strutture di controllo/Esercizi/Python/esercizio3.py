# file esercizio3.py

from __future__ import print_function

a = 5
b = 2.5

print("a = {}, b = {}".format(a, b))

c = a + b

print("{} + {} (risultato float) = {}".format(a, b, c))
# conversione possibile del risultato a intero, ma perdendo la parte decimale
print("{} + {} (convertito a intero) = {}".format(a, b, int(a + b)))

