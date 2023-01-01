# file copyFile.py

from __future__ import print_function

# apre il primo file in sola lettura

file1 = open("helloworld.txt", "r")

# apre il secondo file in scrittura

file2 = open("helloworld2.txt", "w")

# copia il contenuto del primo file nel secondo

file2.write(file1.read())

# chiude entrambi i file

file1.close()
file2.close()

