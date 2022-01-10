# file testMatrix.py

from __future__ import print_function
from sys import stdout
from os import linesep

row = 5
col = 5

# inizializza una matrice di 5 righe * 5 colonne

matr = [[0 for i in range(row)] for j in range(col)]

for i in range(row):
	for j in range(col):
		if i == j:
			matr[i][j] = 1

# stampa la matrice

for i in range(row):
	for j in range(col):
		print(matr[i][j], end=" ");
	stdout.write(linesep)

