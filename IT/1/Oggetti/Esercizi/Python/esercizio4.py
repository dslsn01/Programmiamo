# file esercizio4.py

from __future__ import print_function

class Spaceman(object):
	def __init__(self, name):
		self.__name = name

	def __str__(self):
		return "Sono l'astronauta {}!".format(self.__name)

neil = Spaceman("Neil Armstrong")

# cosa stampa?
print(neil)

