# file types.py

from __future__ import print_function

if hasattr(__builtins__, 'raw_input'): input = raw_input

s = input("Quanti anni hai? ")

# controlla che sia stato digitato un numero

if not s.isdigit():
	print("Numero non valido!")
	exit()

# converte gli anni da stringa a numero intero con int()
age = int(s)

if age >= 18:
	print("Puoi prendere la patente.")
else:
	print("Non puoi ancora prendere la patente!")

