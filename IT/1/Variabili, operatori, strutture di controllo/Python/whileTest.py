# file whileTest.py

from __future__ import print_function
from sys import stdout
from os import linesep

# inizializza la variabile contatore

c = 0

# itera per cinque volte

while c < 5:
	print(c, end=" ")
	c = c + 1

# fine del ciclo

# va a capo
stdout.write(linesep)
print("Fine del ciclo.")

