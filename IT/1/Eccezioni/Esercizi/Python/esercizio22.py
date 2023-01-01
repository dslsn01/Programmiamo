# file esercizio22.py
# -*- coding: utf-8 -*-

from __future__ import print_function
if hasattr(__builtins__, 'raw_input'): input = raw_input

s = input("Quanti animali vuoi inserire? ")

try:
	SIZE = int(s)

	animals = []
	i = 0

	while i < SIZE:
		animal = input("Scrivi un nuovo animale: ").lower()

		try:
			if not animal:
				raise ValueError("Nome non valido!")

			if animal in animals:
				raise ValueError("Animale già presente!")

			animals.append(animal)
			i += 1

		except ValueError as e:
			print(e)

	index = -1

	while index < 0:
		try:
			animal = input("Quale animale vuoi recuperare? ")
			index = animals.index(animal)
			print("L'animale \"{}\" si trova all'indice {}.".format(animal, index))

		except ValueError:
			print("Animale non presente nella lista!")

except ValueError as e:
	print(e)

print("Fine del programma.")

