# file esercizio5.py

from __future__ import print_function
if hasattr(__builtins__, 'raw_input'): input = raw_input

filename = input("Apri il file: ")

try:
	f = open(filename)
	i = 1
	for line in f:
		print("{} {}".format(i, line), end="")
		i += 1

except IOError as e:
	print(e)

