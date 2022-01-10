# file esercizio.py

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
		return "({}, {})".format(self.__x, self.__y)

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
		return "({}, {}, {})".format(self.x, self.y, self.__z)

	z = property(getZ, setZ)

class Plane(object):
	def __init__(self, p1, p2, p3):
		self.__p1 = p1
		self.__p2 = p2
		self.__p3 = p3

	def __str__(self):
		return "Piano definito dai punti P1={}, P2={}, P3={}".format(self.__p1, self.__p2,self.__p3)

p1 = Point3d(0.0, 0.0, 0.0)
p2 = Point3d(1.0, 2.0, 3.0)
p3 = Point3d(3.0, 4.0, 5.0)

pi = Plane(p1=p1, p2=p2, p3=p3)

print(pi)

