# file esercizio32.py

from __future__ import print_function
from sys import stdout
from os import linesep

for i in range(1, 30+1):
	if i % 5 == 0 and i % 3 == 0:
		print("fizzbuzz", end=" ")
	elif i % 3 == 0:
		print("fizz", end=" ")
	elif i % 5 == 0:
		print("buzz", end=" ")
	else:
		print(i, end=" ")

stdout.write(linesep)

