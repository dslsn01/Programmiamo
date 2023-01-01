# file readFile.py

from __future__ import print_function

# apre un file in sola lettura

file1 = open("helloworld.txt", "r")

# stampa il contenuto del file

print(file1.read())

# chiude il file

file1.close()

