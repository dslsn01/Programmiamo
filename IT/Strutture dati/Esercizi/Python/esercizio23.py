# file esercizio23.py

from __future__ import print_function
from sys import stdout
from os import linesep

m = 3 
n = 3

matrix1 = [[1, 2, 3],
		   [3, 4, 5],
		   [5, 6, 7]]

matrix2 = [[7, 6, 5],
		   [5, 4, 3],
		   [3, 2, 1]]

p = [[0 for i in range(m)] for j in range(n)] # matrice del prodotto (per ora nulla)

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
		for k in range(m):
			p[i][j] += matrix1[i][k] + matrix2[k][j]

print("Prodotto di matrici:")

for i in range(m):
	for j in range(n):
		print("{:<3}".format(p[i][j]), end="")
	stdout.write(linesep)

