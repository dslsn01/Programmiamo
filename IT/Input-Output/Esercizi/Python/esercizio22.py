# file esercizio22.py

from __future__ import print_function
if hasattr(__builtins__, 'raw_input'): input = raw_input
from os import path
import filecmp

print("Confronto tra file")

filename1 = input("Primo file: ")
filename2 = input("Secondo file: ")

if path.isfile(filename1) and path.isfile(filename2):
	if filecmp.cmp(filename1, filename2):
		print("I file sono uguali.")
	else:
		print("I file sono diversi!")
else:
	print("Non trovo i file da confrontare!")

