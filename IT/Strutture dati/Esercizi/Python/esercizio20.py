# file esercizio20.py

from __future__ import print_function
from sys import stdout
from os import linesep

m = 3
n = 3

matrix = [[0 for x in range(n)] for x in range(m)]

k = m * n

for i in range(m):
	for j in range(n):
		matrix[i][j] = k
		k -= 1

for i in range(m):
	for j in range(n):
		print("{:<2}".format(matrix[i][j]), end="")

	stdout.write(linesep)

