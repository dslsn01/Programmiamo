# file esercizio6.py

from __future__ import print_function

class Spaceman(object):
	def __init__(self, name):
		self.setName(name)

	def getName(self):
		return self.__name

	def setName(self, name):
		self.__name = name

	# metodo che permette agli astronauti di muoversi nello spazio
	def floatInSpace(self):
		print("{} galleggia nello spazio...".format(self.name))

	def __str__(self):
		return "Sono l'astronauta {}!".format(self.name)

	name = property(getName, setName)

neil = Spaceman("Neil Armstrong")
neil.floatInSpace();

