# file esercizio20.py

from __future__ import print_function
from sys import stdout
from os import linesep

for i in range(1, 6):
	for j in range(1, 6):
		if j > i:
			stdout.write("0" + " ")
		else:
			stdout.write(str(1) + " ")
	stdout.write(linesep) 

