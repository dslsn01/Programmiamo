# file duckTyping.py

from __future__ import print_function

# le tre classi "Dog", "Cat" e "Duck" sono di tipi diversi, ma tutt'e tre dichiarano il metodo "fremitus()"

class Dog:
	def fremitus(self):
		print("Bau!")

class Cat:
	def fremitus(self):
		print("Miao!")

class Duck:
	def fremitus(self):
		print("Quack!")

# il metodo "checkup()" della classe "Vet" riceve un oggetto di qualsiasi tipo che definisca il metodo "fremitus()" 

class Vet:
	def checkup(self, animal):
		print("Dica 33!")
		animal.fremitus()

pluto = Dog()
tom = Cat()
donald = Duck()

patients = [pluto, tom, donald]

vet = Vet()

for p in patients:
	vet.checkup(p)

