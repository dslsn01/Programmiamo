# file esercizio21.py

from __future__ import print_function

class Smartphone(object):
	def __init__(self, model):
		self.__model = model

	def __str__(self):
		return self.__model

class Factory(object):
	instances = 0

	@staticmethod
	def newSmartphone(model):
		Factory.instances += 1
		return Smartphone(model)

if __name__ == "__main__":
	iphone = Factory.newSmartphone("iPhone")
	samsung = Factory.newSmartphone("Samsung")
	huawei = Factory.newSmartphone("Huawei")

	print("Prodotti {} nuovi smartphone.".format(Factory.instances))

	print(iphone)
	print(samsung)
	print(huawei)

