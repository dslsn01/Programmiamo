# file esercizio28.py

from __future__ import print_function
from sys import stdout
from os import linesep

def fibonacci(n):
	a = 0
	b = 1
	for i in range(0, n):
		prev = a
		a = b
		b = prev + b
	return a

for n in range(1, 21):
	print(fibonacci(n), end=" ")

stdout.write(linesep)

