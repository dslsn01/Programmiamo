# file esercizio9.py

from __future__ import print_function
if hasattr(__builtins__, 'raw_input'): input = raw_input
from os import path, linesep
from datetime import datetime

filename = input("Apri il file: ")

if path.isfile(filename):
	print("#### File esistente aperto in lettura. ####")
	f = open(filename, "r")
	for line in f:
		print(line, end="")
else:
	f = open(filename, "w")
	date = datetime.now()
	f.write("File creato il " + date.strftime("%d-%m-%Y alle ore %H:%M:%S") + linesep)

f.close()

