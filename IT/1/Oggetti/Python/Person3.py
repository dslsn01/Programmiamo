# file Person3.py

from __future__ import print_function

class Person(object):
	def __init__(self, name, surname):
		self.name = name
		self.surname = surname

	# setter e getter del nome

	def getName(self):
		return self.__name

	def setName(self, name):
		self.__name = name if name else "John"

	# setter e getter del cognome

	def getSurname(self):
		return self.__surname

	def setSurname(self, surname):
		self.__surname = surname if surname else "Doe"

	# registra i setter e getter per nome e cognome

	name = property(getName, setName)
	surname = property(getSurname, setSurname)

	# dichiarazione del metodo walk()
	def walk(self): 
		print("{} {} passeggia.".format(self.name, self.surname))

p = Person("Walt", "Disney")
p.walk()

p = Person("", "")
p.walk()

