# file esercizio27.py

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

# la classe Cilinder rappresenta un cilindro tridimensionale

class Cilinder(object):
	# ogni cilindro viene definito da altezza e circonferenza alla base
	def __init__(self, base, h):
		self.__base = base
		self.__h = h

	# volume del cilindro: 3.14 * r^2 * h
	def volume(self):
		return self.__base.area() * self.__h

circle = Circle(r=2.0)

print("Area circonferenza alla base: {:.2f} centimetri quadrati.".format(circle.area()))

solid = Cilinder(base=circle, h=3.0)

print("Volume cilindro: {:.2f} centimetri cubi.".format(solid.volume())) 

