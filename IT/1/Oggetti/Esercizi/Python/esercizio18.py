# file esercizio18.py

from __future__ import print_function

class Engine(object):
	def __init__(self, cc):
		self.__cc = cc

	def __str__(self):
		return "motore di {} centimetri cubi".format(self.__cc)

class Vehicle(object):
	def __init__(self, engine):
		self.__engine = engine

	def getEngine(self):
		return self.__engine

	def setEngine(self, e):
		self.__engine = e

	engine = property(getEngine, setEngine)

class Car(Vehicle):
	def __init__(self, model, vin, plate, engine):
		Vehicle.__init__(self, engine)
		self.model = model
		self.vin = vin
		self.plate = plate

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

	model = property(getModel, setModel)
	vin = property(getVin, setVin)
	plate = property(getPlate, setPlate)

	def __str__(self):
		return "{}, targa \"{}\", n. telaio \"{}\", {}".format(self.model, self.plate, self.vin, self.engine)

class Truck(Vehicle):
	def __str__(self):
		return "Camion con {}".format(self.engine)

class Tractor(Vehicle):
	def __str__(self):
		return "Trattore con {}".format(self.engine)

fiat500 = Car(model="Fiat 500", vin="1G8AN12F04Z242828", plate="AS 123 DF", engine=Engine(cc=1400))
classeA = Car(model="Mercedes Classe A", vin="2FZHAZBD21AH02482", plate="CA 128 TD", engine=Engine(cc=1600))
alfaGiulia = Car(model="Alfa Romeo Giulia", vin="2G1115SL7F9174905", plate="EE 119 CA", engine=Engine(cc=2000))

print(fiat500)
print(classeA)
print(alfaGiulia)

truck = Truck(engine=Engine(cc=15000))
tractor = Tractor(engine=Engine(cc=5800))

print(truck)
print(tractor)

