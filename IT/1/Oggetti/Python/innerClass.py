# file innerClasses.py

from __future__ import print_function
from random import randint

# la classe Sprinkler rappresenta un sistema antincendio
class Sprinkler:
	# la classe HeatDetector rappresenta un sistema di rilevamento temperatura
	class HeatDetector:
		# se la temperatura supera i 70 gradi C, potrebbe esserci un incendio

		def heatControl(self, ht):
			print("Temperatura rilevata: {} gradi C.".format(ht))
			return True if ht >= 70 else False

	# fine della classe innestata

	# Il sistema antincendio possiede un rilevatore di temperatura interno

	def __init__(self):
		self.__heatDetector = self.HeatDetector()

	# controlla la temperatura, e nel caso suona l'allarme

	def fire(self, ht):
		fire = self.__heatDetector.heatControl(ht)
		if fire == True:
			print("Possibile incendio!\nI passeggeri sono invitati a raggiungere l'uscita di sicurezza.")

		return fire

sprinkler = Sprinkler()

# controlla periodicamente la temperatura della metropolitana
while (True):
	ht = randint(18, 100)
	if sprinkler.fire(ht) == True:
		break

