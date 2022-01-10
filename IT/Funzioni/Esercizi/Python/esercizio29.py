# file esercizio29.py

from __future__ import print_function
from sys import stdout
from os import linesep

def fibonacci(n):
	if (n <= 1):
		return n
	else:
		return fibonacci(n-1) + fibonacci(n-2)

for n in range(1, 21):
	print(fibonacci(n), end=" ")

stdout.write(linesep)

