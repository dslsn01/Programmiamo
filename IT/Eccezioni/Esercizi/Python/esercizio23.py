# file esercizio23.py

from __future__ import print_function
if hasattr(__builtins__, 'raw_input'): input = raw_input

user = ""

while not user:
	try:
		user = input("Scrivi il tuo nome: ")
		if not user:
			raise ValueError("Nome non valido!")

		print("Ciao, {}!".format(user))

	except ValueError as e:
		print(e)

print("Fine del programma.")

