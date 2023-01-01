# file esercizio20.py

from __future__ import print_function
if hasattr(__builtins__, 'raw_input'): input = raw_input
from os import path
from sys import stdin

filename = input("File da copiare: ")

try:
	bakName = input("Nome file di backup: ")

	if path.isfile(bakName):
		print("Il file \"{}\" esiste. Sovrascriverlo? s | n: ".format(bakName), end="")
		opt = stdin.read(1)

		if opt.lower() != 's':
			print("File \"{}\" ignorato.".format(bakName))
			exit()
		
	backup = open(bakName, "w")

	for line in open(filename, "r").readlines():
		backup.write(line)

	backup.close()

	print("File \"{}\" salvato su disco.".format(backup.name))

except IOError as e:
	print(e)

