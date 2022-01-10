# file multipleInheritance.py
# -*- coding: utf-8 -*-

from __future__ import print_function

class Animal:
	def walk(self):
		print("Sto passeggiando.")

class Flyer:
	def takeFlight(self):
		print("Sto decollando!")

# la classe Person estende le classi Animal e Flyer
class Person(Animal, Flyer):
	pass

p = Person()

print("p è un animale? {}".format(isinstance(p, Animal)))
print("p è un pilota di aereo? {}".format(isinstance(p, Flyer)))

# invoca le funzioni membro ereditate da entrambe le superclassi

p.walk()
p.takeFlight()

