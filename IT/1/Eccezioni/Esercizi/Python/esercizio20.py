# file esercizio20.py
# -*- coding: utf-8 -*-

from __future__ import print_function
if hasattr(__builtins__, 'raw_input'): input = raw_input

s = input("Quanti animali vuoi inserire? ")

try:
	SIZE = int(s)

	if SIZE < 1: exit()

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

	print(animals)

except ValueError as e:
	print(e)

print("Fine del programma.")

