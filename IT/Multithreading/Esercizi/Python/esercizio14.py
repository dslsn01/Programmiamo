# file esercizio14.py

from __future__ import print_function
from multiprocessing import Process, current_process, Lock, Value

def add(lock, value):
	with lock:
		name = current_process().name
		print("{} - variabile (prima dell'incremento): {}".format(name, value.value))

		value.value += 1

		print("{} - variabile (dopo l'incremento): {}".format(name, value.value))

if __name__ == "__main__":
	lock = Lock()
	value = Value('i', 0)

	p1 = Process(target=add, args=(lock, value))
	p2 = Process(target=add, args=(lock, value))
	
	p1.start()
	p2.start()

	p1.join()
	p2.join()

