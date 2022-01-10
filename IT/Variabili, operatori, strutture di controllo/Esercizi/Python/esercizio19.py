# file esercizio19.py

from __future__ import print_function
from sys import stdout
from os import linesep

for i in range(1, 6):
	for j in range(1, 6):
		if j < i:
			print("0", end=" ")
		else:
			print("1", end=" ")

	stdout.write(linesep) 

