# file esercizio22.py

from __future__ import print_function
from sys import stdout
from os import linesep

m = 3
n = 3

matrix1 = [[1, 2, 3], [3, 4, 5], [5, 6, 7]]
matrix2 = [[2, 9, 1], [4, 6, 3], [5, 7, 1]]

print("Prima matrice:")

for i in range(m):
	for j in range(n):
		print("{:<2}".format(matrix1[i][j]), end="")
	stdout.write(linesep)

print("Seconda matrice:")

for i in range(m):
	for j in range(n):
		print("{:<2}".format(matrix2[i][j]), end="")

	stdout.write(linesep)

for i in range(m):
	for j in range(m):
		matrix2[i][j] += matrix1[i][j]

print("Somma delle matrici:")

for i in range(m):
	for j in range(n):
		print("{:<3}".format(matrix2[i][j]), end="")
	stdout.write(linesep)

