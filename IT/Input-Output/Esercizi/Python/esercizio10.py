# file esercizio10.py

from __future__ import print_function
if hasattr(__builtins__, 'raw_input'): input = raw_input
from os import path, linesep
from datetime import datetime

filename = input("Apri il file: ")

date = datetime.now()

if path.isfile(filename):
	f = open(filename, "a")
	f.write("File modificato il " + date.strftime("%d-%m-%Y alle ore %H:%M:%S") + linesep)
else:
	f = open(filename, "w")
	f.write("File creato il " + date.strftime("%d-%m-%Y alle ore %H:%M:%S") + linesep)

f.close()

