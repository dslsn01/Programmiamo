# file farm.py

from __future__ import print_function
from multiprocessing import Process, current_process, Value, Condition
import time
from random import randint

class Barn:
	def __init__(self):
		self.condition = Condition()
		self.bales = Value('i', 0)

	def heap(self):
		for i in range(3):
			self.condition.acquire()

			if self.bales.value > 0:
				self.condition.wait()

			# pausa da 2 a 4 secondi
			time.sleep(randint(2, 4))
			self.bales.value = self.bales.value + 1;
			print("{}: ci sono {} balle di fieno.".format(current_process().name, self.bales.value))

			self.condition.notify()
			self.condition.release()

	def eat(self):
		for i in range(3):
			self.condition.acquire()

			if not self.bales.value:
				self.condition.wait()

			# pausa da 1 a 3 secondi
			time.sleep(randint(1, 3))
			self.bales.value = self.bales.value - 1
			print("{}: ci sono {} balle di fieno.".format(current_process().name, self.bales.value))

			self.condition.notify()
			self.condition.release()

if __name__ == "__main__":
	barn = Barn()
	farmer = Process(target=barn.heap, name="contadino")
	cow = Process(target=barn.eat, name="mucca")

	farmer.start()
	cow.start()

	farmer.join()
	cow.join()

