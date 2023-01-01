# file esercizio16.py

from __future__ import print_function
from sys import stdout
from os import linesep

m = 10
n = 10

for i in range(1, m+1):
	for j in range(1, n+1):
		print("{}\t".format(i * j), end="")
	stdout.write(linesep) 

