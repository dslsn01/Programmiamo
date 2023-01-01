# file esercizio22.py

from __future__ import print_function

# la classe Cat rappresenta un gatto
class Cat(object):
	def __init__(self):
		self.__spec = "gatto"

	def __str__(self):
		return self.__spec

# la classe Dog rappresenta un cane 
class Dog(object):
	def __init__(self):
		self.__spec = "cane"

	def __str__(self):
		return self.__spec

# la classe Cow rappresenta una mucca
class Cow(object):
	def __init__(self):
		self.__spec = "mucca"

	def __str__(self):
		return self.__spec

class Factory(object):
	def getAnimal(self, animal):
		if (animal == "gatto"):
			return Cat()

		if (animal == "cane"):
			return Dog()

		if (animal == "mucca"):
			return Cow()

		return None

if __name__ == "__main__":
	factory = Factory()

	animal = factory.getAnimal("gatto")
	print(animal)

	animal = factory.getAnimal("cane")
	print(animal)

	animal = factory.getAnimal("mucca")
	print(animal)

