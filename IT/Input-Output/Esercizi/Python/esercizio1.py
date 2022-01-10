# file esercizio1.py

from __future__ import print_function
from os import path

if path.isfile("file.txt"):
	print("Il file esiste.")
else:
	print("Il file non esiste!")

