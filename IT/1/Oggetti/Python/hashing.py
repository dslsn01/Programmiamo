# file hashing.py

from __future__ import print_function

# la classe Car rappresenta un'automobile

class Car(object):
	# identifichiamo ogni auto dal numero di telaio e dal numero di targa
	def __init__(self, vin, licensePlate):
		self.__vin = vin
		self.__licensePlate = licensePlate

	def setVin(self, vin):
		self.__vin = vin

	def getVin(self):
		return self.__vin

	def setLicensePlate(self, licensePlate):
		self.__licensePlate = licensePlate

	def getLicensePlate(self):
		return self.__licensePlate

	vin = property(getVin, setVin)
	licensePlate = property(getLicensePlate, setLicensePlate)

	def __str__(self):
		return "Auto con n. di telaio {} e targa {}".format(self.__vin, self.__licensePlate)

	# due auto sono uguali se e solo se hanno lo stesso numero di telaio e la stessa targa, ossia se sono la stessa auto

	def __eq__(self, other):
		if not isinstance(other, Car):
			return False

		return (self.vin == other.vin) & (self.licensePlate == other.licensePlate)

	# il metodo __hash__() restituisce l'hash della tupla che contiene V.I.N. e numero di targa

	def __hash__(self):
		# calcola l'hash complessivo di targa e numero di telaio, e moltiplica il risultato per una costante prima, per migliorare le prestazioni
		prime = 31
		result = 1
		result = prime * result + hash((self.vin, self.licensePlate))
		return result

# crea tre nuove auto

car1 = Car("JM1BD5215B0878543", "569STE")
car2 = Car("1G2NF52F72M733360", "KRC 535")
car3 = Car("JA32W6FV6AU032375", "527 OTG")

# verifica l'uguaglianza tra automobili

car1copy = Car("JM1BD5215B0878543", "569STE")
print("L'auto originale è uguale alla sua copia?", car1 == car1copy)

# crea tre piloti

driver1 = "Ayrton Senna"
driver2 = "Alain Prost"
driver3 = "Gilles Villeneuve"

d = {}

d[car1] = driver1
d[car2] = driver2
d[car3] = driver3

for car, driver in d.items():
	print("Veicolo: {}, Pilota: {}".format(car, driver))

# recupera il pilota associato all'auto

if car1 in d:
	print("Trovata {}, il suo pilota è: {}".format(car1, d[car1]))
else:
	print("Automobile non trovata!")

