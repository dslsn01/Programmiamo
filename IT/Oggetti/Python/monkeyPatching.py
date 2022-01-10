# file monkeyPatching.py

from __future__ import print_function

class Person:
	def __init__(self, name):
		self.__name = name

	def __str__(self):
		return self.__name

# crea tre nuove persone

guest1 = Person("Signor Anderson")
ghost = Person("Fantasma")
guest2 = Person("Signor Jensen")

# aggiunge una nuova variabile a ogni persona per memorizzare il numero di stanza

guest1.room = 14
ghost.room = 13
guest2.room = 12

goldenLion = [guest1, ghost, guest2]

for guest in goldenLion:
	print("Il {} alloggia nella stanza n.{}".format(guest, guest.room))

