# file esercizio19.py

from __future__ import print_function
from multiprocessing import Process, current_process, Semaphore
from time import sleep
from random import randint

class PollingStation:
	def __init__(self):
		self.__cabin = Semaphore(4)

	def vote(self):
		# attende tra zero e 10 secondi per entrare nel seggio elettorale
		sleep(randint(0, 10))

		pName = current_process().name
		print("{} entra nel seggio elettorale.".format(pName))

		self.__cabin.acquire()
		sleep(randint(5, 10))
		print("{} ha votato.".format(pName))
		self.__cabin.release()

def target(pStation):
	pStation.vote()

if __name__ == "__main__":
	pStation = PollingStation()
	procs = [Process(target=target, args=(pStation,)) for i in range(25)]

	for voter in procs:
		voter.start()

	for voter in procs:
		voter.join()

