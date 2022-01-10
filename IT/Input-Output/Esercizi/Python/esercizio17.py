# file esercizio17.py

from __future__ import print_function

try:
	doc = open("file.txt", "r")
	lines = doc.readlines()

	j = len(lines)
	i = j - 3 if j >= 3 else 0

	for i in range(i, j):
		print(lines[i], end="")

	doc.close()

except IOError as e:
	print(e)

