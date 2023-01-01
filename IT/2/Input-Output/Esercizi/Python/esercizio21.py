# file esercizio21.py

from __future__ import print_function
if hasattr(__builtins__, 'raw_input'): input = raw_input
import filecmp

print("Confronto tra file")

filename1 = input("Primo file: ")
filename2 = input("Secondo file: ")

if filecmp.cmp(filename1, filename2):
	print("I file sono uguali.")
else:
	print("I file sono diversi!")

