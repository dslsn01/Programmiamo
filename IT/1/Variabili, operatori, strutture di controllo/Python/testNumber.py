# file testNumber.py

from __future__ import print_function

if hasattr(__builtins__, 'raw_input'): input = raw_input

# legge un numero da tastiera

s = input("Inserisci un intero positivo compreso tra 2 e 10: ")

if not s.isdigit():
	print("Numero non valido!")
	exit()

# converte la stringa letta da tastiera in un numero intero

n = int(s)

# controlla che il valore inserito non sia negativo o nullo

if not(n > 0) or n == 0:
	print("Il numero inserito dev'essere maggiore di zero!")
else:
	# controlla che il valore inserito non sia minore di 2 o maggiore di 10

	if (n >= 2) and (n <= 10):
		print("Hai digitato {}.".format(n))
	else:
		print("Valore fuori dell'intervallo!")

