# file esercizio6.py

from __future__ import print_function
if hasattr(__builtins__, 'raw_input'): input = raw_input

filename = input("Apri il file: ")

try:
	f = open(filename)
	lines = f.readlines()[::-1]
	i = len(lines)

	for line in lines:
		print("{} {}".format(i, line), end="")
		i -= 1

except IOError as e:
	print(e)

