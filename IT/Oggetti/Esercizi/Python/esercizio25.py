# file esercizio25.py

from __future__ import print_function
from math import pow, sqrt

class Point2d(object):
	def __init__(self, x, y):
		self.__x = x
		self.__y = y

	def getX(self):
		return self.__x

	def setX(self, x):
		self.__x = x

	def getY(self):
		return self.__y

	def setY(self, y):
		self.__y = y

	def __str__(self):
		return "(x={}, y={})".format(self.__x, self.__y)

	x = property(getX, setX)
	y = property(getY, setY)

class Point3d(Point2d):
	def __init__(self, x, y, z):
		super(Point3d, self).__init__(x, y)
		self.__z = z

	def getX(self):
		return self.__x

	def setZ(self, z):
		self.__z = z

	def getZ(self):
		return self.__z

	def __str__(self):
		return "(x={}, y={}, z={})".format(self.x, self.y, self.z)

	z = property(getZ, setZ)

class Segment(object):
	def __init__(self, a, b):
		self.__a = a
		self.__b = b

	def getA(self):
		return self.__a

	def setA(self, a):
		self.__a = a

	def getB(self):
		return self.__b

	def setB(self, b):
		self.__b = b

	def length(self):
		return sqrt((self.a.x - self.b.x)**2 + (self.a.y - self.b.y)**2 + (self.a.z - self.b.z)**2)

	a = property(getA, setA)
	b = property(getB, setB)

o = Point3d(0, 0, 0)
p = Point3d(1, 2, 3)
s = Segment(a=o, b=p)

print("O = {}, P = {}".format(o, p))
print("Distanza tra i due punti: {:.2f} centimetri.".format(s.length()))

