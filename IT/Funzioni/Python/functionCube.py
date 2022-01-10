# file functionCube.py

from __future__ import print_function

# definizione della funzione cube()

def cube(n):
	cube = n * n * n
	return cube

# dichiara tre variabili

n1 = 3
n2 = 4
n3 = 5

# calcola i cubi invocando la funzione cube()

cube1 = cube(n1)
cube2 = cube(n2)
cube3 = cube(n3)

# stampa i cubi

print("{} al cubo = {}".format(n1, cube1))
print("{} al cubo = {}".format(n2, cube2))
print("{} al cubo = {}".format(n3, cube3))

