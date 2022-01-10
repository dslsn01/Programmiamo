# file esercizio16.py

from __future__ import print_function

try:
	doc = open("file.txt", "r")

	for i in range(3):
		print(doc.readline(), end="")

	doc.close()

except IOError as e:
	print(e)

