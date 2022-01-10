# file esercizio12.py
# -*- coding: utf-8 -*-

from __future__ import print_function

# gli "astronauti" sono tutti "persone": "Person" è la superclasse comune

class Person(object):
	# ogni persona ha un nome: la proprietà "nome" è dichiarata nella superclasse Person.
	def __init__(self, name):
		self.setName(name)

	def getName(self):
		return self.__name

	def setName(self, name):
		self.__name = name

	name = property(getName, setName)

class Traveler(object):
	pass

class Spaceman(Person, Traveler):
	def floatInSpace(self):
		print("{} galleggia nello spazio...".format(self.name))

	def __str__(self):
		return "Sono l'astronauta {}!".format(self.name)

neil = Spaceman("Neil Armstrong")

if isinstance(neil, Person):
	print("L'astronauta {} è una persona!".format(neil.name))

if isinstance(neil, Traveler):
	print("L'astronauta {} è un viaggiatore!".format(neil.name))

