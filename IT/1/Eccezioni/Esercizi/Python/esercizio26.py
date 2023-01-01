# file esercizio26.py
# -*- coding: utf-8 -*-

from __future__ import print_function
if hasattr(__builtins__, 'raw_input'): input = raw_input

class InvalidDDException(ValueError):
	pass

class InvalidMMException(ValueError):
	pass

class InvalidYYYYException(ValueError):
	pass

class MyDate(object):
	def __init__(self, dd, mm, yyyy):
		try:
			self.yyyy = yyyy
		except InvalidYYYYException as e:
			print(e)
			self.yyyy = 1970
		try:
			self.mm = mm
		except InvalidMMException as e:
			print(e)
			self.mm = 1
		try:
			self.dd = dd
		except InvalidDDException as e:
			print(e)
			self.dd = 1

	def getDD(self):
		return self.__dd

	def setDD(self, dd):
		minDD = 1
		maxDD = 0

		if dd < 1:
			raise InvalidDDException("Giorno ({}) non valido!".format(dd))

		if self.mm in [4, 6, 9, 11]:
			maxDD = 30
		elif self.mm == 2:
			maxDD = 28
		else:
			maxDD = 31

		if dd > maxDD:
			raise InvalidDDException("Giorno ({}) non valido!".format(dd))

		self.__dd = dd

	def getMM(self):
		return self.__mm

	def setMM(self, mm):
		if mm < 1 or mm > 12:
			raise InvalidMMException("Mese ({}) non valido!".format(mm))
		self.__mm = mm

	def getYYYY(self):
		return self.__yyyy

	def setYYYY(self, yyyy):
		if (yyyy <= 0):
			raise InvalidYYYYException("Anno ({}) non valido!".format(yyyy))
		self.__yyyy = yyyy

	def __str__(self):
		return "{}-{}-{}".format(self.dd, self.mm, self.yyyy)

	dd = property(getDD, setDD)
	mm = property(getMM, setMM)
	yyyy = property(getYYYY, setYYYY)

d = MyDate(dd=1, mm=1, yyyy=2000)
print(d)

d = MyDate(dd=32, mm=1, yyyy=2000)
print(d)

d = MyDate(dd=1, mm=13, yyyy=2000)
print(d)

d = MyDate(dd=1, mm=1, yyyy=-1)
print(d)

