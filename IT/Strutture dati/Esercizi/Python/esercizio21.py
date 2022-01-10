# file esercizio21.py

from __future__ import print_function
from sys import stdout
from os import linesep

m = 3
n = 3

matrix = [[1, 2, 3], [3, 4, 5], [5, 6, 7]]

print("Matrice originale:")

for i in range(m):
	for j in range(n):
		print("{:<2}".format(matrix[i][j]), end="")
	stdout.write(linesep)

sc = 3

for i in range(m):
	for j in range(m):
		matrix[i][j] *= sc

print("Matrice moltiplicata per lo scalare {}:".format(sc))

for i in range(m):
	for j in range(n):
		print("{:<3}".format(matrix[i][j]), end="")
	stdout.write(linesep)

