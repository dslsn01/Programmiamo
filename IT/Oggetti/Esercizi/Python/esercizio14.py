# file esercizio14.py

class Engine(object):
	def __init__(self, cc):
		self.__cc = cc

class Car(object):
	def __init__(self, model, vin, plate, engine):
		self.__model = model
		self.__vin = vin
		self.__plate = plate
		self.__engine = engine

