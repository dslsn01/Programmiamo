# file esercizio18.py

from __future__ import print_function
if hasattr(__builtins__, 'raw_input'): input = raw_input

filename = input("Apri il file: ")

doc = open(filename, "r")

linecount = sum(1 for l in doc)

if linecount > 10:
	offset = 0
	i = 1
	doc.seek(0)
	while i <= (linecount - 10):
		offset += len(doc.readline())
		i += 1
	doc.seek(offset)

for line in doc:
	print(line, end="")

doc.close()

