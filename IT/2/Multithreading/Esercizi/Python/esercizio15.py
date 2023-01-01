# file esercizio15.py

from __future__ import print_function
from multiprocessing import Process, current_process, Value, Condition

def add(condition, value):
	condition.acquire()

	while (value.value == 1): condition.wait()

	name = current_process().name
	print("{} - variabile (prima dell'incremento): {}".format(name, value.value))

	value.value += 1

	print("{} - variabile (dopo l'incremento): {}".format(name, value.value))

	condition.notify()
	condition.release()

def subtr(condition, value):
	condition.acquire()

	while (value.value == 0): condition.wait()

	name = current_process().name
	print("{} - variabile (prima del decremento): {}".format(name, value.value))

	value.value -= 1

	print("{} - variabile (dopo il decremento): {}".format(name, value.value))

	condition.notify()
	condition.release()

if __name__ == "__main__":
	condition = Condition()
	value = Value('i', 0)

	p1 = Process(target=add, args=(condition, value))
	p2 = Process(target=subtr, args=(condition, value))

	p1.start()
	p2.start()

	p1.join()
	p2.join()

