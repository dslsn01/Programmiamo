# file esercizio15.py

class Engine(object):
	def __init__(self, cc):
		self.__cc = cc

class Car(object):
	def __init__(self, model, vin, plate, engine):
		self.model = model
		self.vin = vin
		self.plate = plate
		self.engine = engine

	def getModel(self):
		return self.__model

	def setModel(self, model):
		self.__model = model

	def getVin(self):
		return self.__vin

	def setVin(self, vin):
		self.__vin = vin

	def getPlate(self):
		return self.__plate

	def setPlate(self, plate):
		self.__plate = plate

	def getEngine(self):
		return self.__engine

	def setEngine(self, engine):
		self.__engine = engine

	model = property(getModel, setModel)
	vin = property(getVin, setVin)
	plate = property(getPlate, setPlate)
	engine = property(getEngine, setEngine)

