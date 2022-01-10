# file polym.py

from __future__ import print_function

# dichiara il campo "age" nella superclasse Animal
class Animal(object):
	def __init__(self, age):
		self.age = age

	def getAge(self):
		return self.__age

	def setAge(self, age):
		self.__age = age

	age = property(getAge, setAge)

# la classe Person estende la classe Animal ed eredita i membri

class Person(Animal):
	def __init__(self, name, surname, age):
		super(Person, self).__init__(age)
		self.__name = name
		self.__surname = surname

	def __str__(self):
		return "{} {}, {} anni.".format(self.__name, self.__surname, self.age)

# crea un'istanza della sottoclasse Person

p = Person("John", "Doe", 30)

# verifica che p appartenga al tipo Person, ...ma anche al tipo Animal

print("p animale? {}".format(isinstance(p, Animal)))
print("p persona? {}".format(isinstance(p, Person)))

# stampa l'oggetto con il metodo __str__()
print(p)

