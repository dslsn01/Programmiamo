# file esercizio17.py

from __future__ import print_function
from sys import stdout
from os import linesep

for i in range(1, 6):
	for j in range(1, 6):
		if i == j:
			print("{}".format(i), end="")
		else:
			stdout.write(" ")
	stdout.write(linesep) 

