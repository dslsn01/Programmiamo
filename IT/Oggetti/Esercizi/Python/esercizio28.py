# file esercizio28.py

from __future__ import print_function
from math import pi

# la classe Circle rappresenta una circonferenza

class Circle(object):
	# ogni circonferenza viene definita dal suo raggio
	def __init__(self, r):
		self.__r = r

	# area del cerchio = Pi greco * raggio al quadrato
	def area(self):
		return pi * self.__r * self.__r

# la classe Cone rappresenta un cono tridimensionale

class Cone(object):
	# ogni cono viene definito da altezza e circonferenza alla base
	def __init__(self, base, h):
		self.__base = base
		self.__h = h

	# volume del cono: (3.14 * r^2 * h) / 3
	def volume(self):
		return (self.__base.area() * self.__h) / 3

circle = Circle(r=2.0)

print("Area circonferenza alla base: {:.2f} centimetri quadrati.".format(circle.area()))

solid = Cone(base=circle, h=3.0)

print("Volume cono: {:.2f} centimetri cubi.".format(solid.volume())) 

