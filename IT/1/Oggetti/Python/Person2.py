# file Person2.py

from __future__ import print_function

class Person:
	# dichiarazione del metodo __init__(), che inizializza i campi "name" e "surname"
	def __init__(self, name, surname):
		self.name = name
		self.surname = surname

# crea un oggetto di tipo persona
p = Person("John", "Doe")
print("Il nostro uomo si chiama {} {}.".format(p.name, p.surname))

