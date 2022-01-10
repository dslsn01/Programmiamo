# file bitwiseops.py

from __future__ import print_function
from sys import stdout
from os import linesep

# insieme A: numeri pari
a = 0

# insieme B: numeri dispari
b = 0

# insieme C: multipli di 3, pari e dispari
c = 0

for i in range(2, 32):
	if i & 1 == 0:
		a |= 1 << i

for i in range(0, 32):
	if i & 1 == 1:
		b |= 1 << i

i = 3
while i < 32:
	c |= 1 << i
	i += 3

# stampa gli elementi di A

print("A = {{{0:>032b}}}".format(a))

for i in range(0, 32):
	if a & (1 << i):
		print(i, end=" ")

stdout.write(linesep)

# stampa gli elementi di B

print("B = {{{0:>032b}}}".format(b))

for i in range(0, 32):
	if b & (1 << i):
		print(i, end=" ")

stdout.write(linesep)

# stampa gli elementi di C

print("C = {{{0:>032b}}}".format(c))

for i in range(0, 32):
	if c & (1 << i):
		print(i, end=" ")

stdout.write(linesep)

# unione insiemistica A u B

aub = a | b

print("A u B = {{{0:>032b}}}".format(aub))

for i in range(0, 32):
	if aub & (1 << i):
		print(i, end=" ")

stdout.write(linesep)

# intersezione insiemistica: B & C (multipli di tre che sono dispari)

bec = b & c

print("B & C = {{{0:>032b}}}".format(bec))

for i in range(0, 32):
	if bec & (1 << i):
		print(i, end=" ")

stdout.write(linesep)

# complemento (A u B) \ C (pari e dispari meno i multipli di tre)

aub_c = aub & ~c

print("(A u B) \\ C = {{{0:>032b}}}".format(aub_c))

for i in range(0, 32):
	if aub_c & (1 << i):
		print(i, end=" ")

stdout.write(linesep)

# differenza simmetrica B ^ C: numeri dispari oppure pari multipli di tre

b_c = b ^ c

print("B ^ C = {{{0:>032b}}}".format(b_c))

for i in range(0, 32):
	if b_c & (1 << i):
		print(i, end=" ")

stdout.write(linesep)

