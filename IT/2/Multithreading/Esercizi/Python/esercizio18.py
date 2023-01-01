# file esercizio18.py

from __future__ import print_function
from multiprocessing import Process, current_process, Semaphore
from time import sleep
from random import randint

class VendingMachine:
	def __init__(self):
		self.__machine = Semaphore(1)
		self.__drinks = [ "acqua", "Coca Cola", "Fanta", "Sprite", "the freddo" ]

	def select(self):
		# attende tra zero e 10 secondi per entrare nell'area di ristoro
		sleep(randint(0, 10))

		pName = current_process().name
		print("{} entra nella zona pausa.".format(pName))

		self.__machine.acquire()
		sleep(randint(5, 10))
		pick = randint(0, len(self.__drinks)-1)
		print("{} ha selezionato {}.".format(pName, self.__drinks[pick]))
		self.__machine.release()

def target(dMachine):
	dMachine.select()

if __name__ == "__main__":
	dMachine = VendingMachine()
	procs = [Process(target=target, args=(dMachine,)) for i in range(10)]

	for consumer in procs:
		consumer.start()

	for consumer in procs:
		consumer.join()

