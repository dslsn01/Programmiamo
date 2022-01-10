# file esercizio5.py

from __future__ import print_function

class Spaceman(object):
	def __init__(self, name):
		self.setName(name)

	def getName(self):
		return self.__name

	def setName(self, name):
		self.__name = name

	def __str__(self):
		return "Sono l'astronauta {}!".format(self.name)

	name = property(getName, setName)

neil = Spaceman("Neil Armstrong")
print(neil)

