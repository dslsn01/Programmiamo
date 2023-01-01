# file staticMembers.py

from __future__ import print_function

class IPad(object):
	# dichiara un campo statico
	counter = 0

	# dichiara un metodo statico
	@staticmethod
	def getCounter():
		return IPad.counter

	def __init__(self, model):
		self.model = model
		IPad.counter += 1

	def setModel(self, model):
		self.__model = model

	def getModel(self):
		return self.__model

	model = property(getModel, setModel)

ipad1 = IPad("Apple IPad Pro")
ipad2 = IPad("Apple IPad Mini 2")
ipad3 = IPad("Apple IPad Air")

print("Prodotto {}.".format(ipad1.model))
print("Prodotto {}.".format(ipad2.model))
print("Prodotto {}.".format(ipad3.model))

print("Sono stati prodotti {} pezzi in totale.".format(IPad.getCounter()))

