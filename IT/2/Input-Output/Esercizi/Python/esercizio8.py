# file esercizio8.py

from __future__ import print_function
if hasattr(__builtins__, 'raw_input'): input = raw_input
from datetime import datetime
from os import linesep

filename = input("Apri il file: ")
f = open(filename, "w")

date = datetime.now()

f.write("File creato il " + date.strftime("%d-%m-%Y alle ore %H:%M:%S") + linesep)
f.close()

