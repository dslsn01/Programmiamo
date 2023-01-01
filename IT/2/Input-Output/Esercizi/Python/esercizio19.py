# file esercizio19.py

from __future__ import print_function
if hasattr(__builtins__, 'raw_input'): input = raw_input
filename = input("File da copiare: ")

try:
	doc = open(filename, "r")

	bakName = doc.name + ".bak"
	backup = open(bakName, "w")

	for line in doc:
		backup.write(line)

	doc.close()
	backup.close()

	print("File \"{}\" salvato su disco.".format(backup.name))

except IOError as e:
	print(e)

