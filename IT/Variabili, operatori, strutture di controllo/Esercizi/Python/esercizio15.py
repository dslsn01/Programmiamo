# file esercizio15.py

from __future__ import print_function
from sys import stdout
from os import linesep

m = 10
n = 10
i = 1

while i <= m:
	j = 1
	while j <= n:
		print("{}\t".format(i * j), end="")
		j += 1

	i += 1
	stdout.write(linesep)

