# file esercizio23.py

from __future__ import print_function

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

o = Point2d(0, 0)
p = Point2d(1, 2)

print("O = {}, P = {}".format(o, p))

