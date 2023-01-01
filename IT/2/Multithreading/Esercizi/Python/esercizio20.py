# file esercizio20.py

from __future__ import print_function
from multiprocessing import Process, current_process, Value, Semaphore
from random import randint
from time import sleep, time

class Barrier:
	def __init__(self, n):
		self.__n = n;
		self.__count = Value('i', 0)
		self.__mutex = Semaphore(1)
		self.__barrier = Semaphore(0)

	def wait(self):
		self.__mutex.acquire()
		self.__count.value += 1
		self.__mutex.release()

		if (self.__count.value == self.__n):
			self.__barrier.release()

		self.__barrier.acquire()
		self.__barrier.release()

def target(barrier):
	sleep(randint(3, 8))
	barrier.wait()

	# stampa l'istante in millisecondi

	print("{} {}".format(int(round(time()*1000)), current_process().name))

if __name__ == "__main__":
	nProcs = 3
	barrier = Barrier(nProcs)

	procs = [Process(target=target, args=(barrier,)) for i in range(nProcs)]

	for p in procs:
		p.start()

	for p in procs:
		p.join()

