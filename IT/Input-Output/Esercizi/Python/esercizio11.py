# file esercizio11.py

from __future__ import print_function
if hasattr(__builtins__, 'raw_input'): input = raw_input
from os import linesep

s = input("Scrivi una parola o una frase: ")

doc = open("file.txt", "w")

doc.write(s)
doc.write(linesep)
doc.close()

print("File \"{}\" salvato su disco.".format(doc.name))

