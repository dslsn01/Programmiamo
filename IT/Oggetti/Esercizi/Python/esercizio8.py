# file esercizio8.py

from __future__ import print_function

class Spaceman(object):
	def __init__(self, name):
		self.setName(name)

	def getName(self):
		return self.__name

	def setName(self, name):
		self.__name = name

	def floatInSpace(self):
		print("{} galleggia nello spazio...".format(self.name))

	def __str__(self):
		return "Sono l'astronauta {}!".format(self.name)

	name = property(getName, setName)

class Pilot(Spaceman):
	def __str__(self):
		return "Sono il pilota {}.".format(self.name)

class Explorer(Spaceman):
	def __str__(self):
		return "Sono l'esploratore {}.".format(self.name)

buzz = Pilot("Buzz Aldrin")
neil = Explorer("Neil Armstrong")

print(buzz)
print(neil)

