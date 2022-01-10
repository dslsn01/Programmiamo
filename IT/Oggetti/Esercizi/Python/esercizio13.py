# file esercizio13.py
# -*- coding: utf-8 -*-

from __future__ import print_function

# "astronauti" e "passeggeri" sono tutti "persone": "Person" è la superclasse comune

class Person(object):
	def __init__(self, name):
		self.setName(name)

	def getName(self):
		return self.__name

	def setName(self, name):
		self.__name = name

	name = property(getName, setName)

class Spaceman(Person):
	def floatInSpace(self):
		print("{} galleggia nello spazio...".format(self.name))

	def __str__(self):
		return "Sono l'astronauta {}!".format(self.name)

class Passenger(Person):
	pass

class Spaceshuttle:
	def welcome(self, spaceman):
		print("Benvenuto sullo shuttle, {}!".format(spaceman.name))

buzz = Spaceman("Buzz Aldrin")
neil = Spaceman("Neil Armstrong")
jBloggs = Passenger("Joe Bloggs")

shuttle = Spaceshuttle()

# il metodo welcome() dello shuttle può ricevere una persona generica
shuttle.welcome(buzz)
shuttle.welcome(neil)
shuttle.welcome(jBloggs)

