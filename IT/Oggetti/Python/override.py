# file override.py

from __future__ import print_function

class Animal:
	# definizione originale del metodo foo()
	def foo(self):
		print("Ciao, sono un animale!")

class Person(Animal):
	# override del metodo foo() ereditato dalla superclasse Animal
	def foo(self):
		print("Ciao, sono una persona!")

# crea un'istanza della superclasse Animal

a = Animal()

# ...invoca il metodo foo() definito nella classe Animal

a.foo()

# crea un'istanza della sottoclasse Person

p = Person()

# ...invoca il metodo foo() ridefinito nella classe Person

p.foo()

