# file esercizio29.py

from __future__ import print_function
from math import pi

# la classe Circle rappresenta una circonferenza

class Circle(object):
	# ogni circonferenza viene definita dal suo raggio
	def __init__(self, r):
		self.r = r

	# area del cerchio = Pi greco * raggio al quadrato
	def area(self):
		return pi * self.__r * self.__r

	def getR(self):
		return self.__r

	def setR(self, r):
		self.__r = r

	r = property(getR, setR)

# la classe Sphere rappresenta una sfera

class Sphere(object):
	# la sfera viene definita dal suo cerchio massimo
	def __init__(self, circle):
		self.__circle = circle

	# volume della sfera: (4 * 3.14 * r^3) / 3
	def volume(self):
		return (4 * self.__circle.area() * self.__circle.r) / 3

circle = Circle(r=2.0)

print("Area circonferenza alla base: {:.2f} centimetri quadrati.".format(circle.area()))

sphere = Sphere(circle=circle)

print("Volume sfera: {:.2f} centimetri cubi.".format(sphere.volume())) 

