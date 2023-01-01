# file esercizio24.py

from __future__ import print_function
if hasattr(__builtins__, 'raw_input'): input = raw_input
from datetime import date

checked = False
user = ""
age = -1

while not checked:
	try:
		if not user:
			user = input("Scrivi il tuo nome: ")
			if not user:
				raise ValueError("Nome non valido!")

		if age < 0:
			year = int(input("Il tuo anno di nascita: "))
			currYear = date.today().year

			if year <= 0 or year > currYear:
				raise ValueError("Anno di nascita non valido!")

			age = currYear - year

		print("Ciao, {}! Hai {} anni.".format(user, age))
		checked = True

	except ValueError as e:
		print(e)

print("Fine del programma.")

