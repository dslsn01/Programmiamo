# file esercizio30.py

from __future__ import print_function
from math import pi

class Circle(object):
	def __init__(self, r):
		self.r = r

	def area(self):
		return pi * self.__r * self.__r

	def getR(self):
		return self.__r

	def setR(self, r):
		self.__r = r

	r = property(getR, setR)

class Cilinder(object):
	def __init__(self, base, h):
		self.__base = base
		self.__h = h

	def volume(self):
		return self.__base.area() * self.__h

	def draw(self):
		print("Cilindro di raggio {} centimetri e altezza {} centimetri.".format(self.__base.r, self.__h))

# cono
class Cone(object):
	def __init__(self, base, h):
		self.__base = base
		self.__h = h

	def volume(self):
		return (self.__base.area() * self.__h) / 3

	def draw(self):
		print("Cono di raggio {} centimetri e altezza {} centimetri.".format(self.__base.r, self.__h))

# sfera
class Sphere(object):
	def __init__(self, circle):
		self.__circle = circle

	def volume(self):
		return (4 * self.__circle.area() * self.__circle.r) / 3

	def draw(self):
		print("Sfera di raggio {} centimetri.".format(self.__circle.r))

class Geometry(object):
	def getSolid(self, solid):
		if solid == "cilindro":
			return Cilinder(base=Circle(2.0), h=3.0)

		if solid == "cono":
			return Cone(base=Circle(2.0), h=3.0)

		if solid == "sfera":
			return Sphere(circle=Circle(2.0))

		return None

if __name__ == "__main__":
	geometry = Geometry()

	shape = geometry.getSolid("cilindro")
	shape.draw()

	shape = geometry.getSolid("cono")
	shape.draw()

	shape = geometry.getSolid("sfera")
	shape.draw()

