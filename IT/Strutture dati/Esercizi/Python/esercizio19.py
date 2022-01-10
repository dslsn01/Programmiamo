# file esercizio19.py

from __future__ import print_function
from sys import stdout
from os import linesep

li1 = [i for i in range(2, 20+1, 2)]
li2 = [i for i in range(3, 30+1, 3)]

print(li1)
print(li2)

print("Elementi comuni:", end=" ")

for i in range(len(li1)):
	for j in range(len(li2)):
		if li1[i] == li2[j]:
			print(li1[i], end=" ")

stdout.write(linesep)

