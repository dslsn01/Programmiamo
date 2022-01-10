# file receptionist.py

from __future__ import print_function
if hasattr(__builtins__, 'raw_input'): input = raw_input

print("Benvenuto nell'Hotel!")

n = input("Nome: ")
s = input("Cognome: ")

print("Benvenuto, {} {}!".format(n, s))

