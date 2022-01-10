# file esercizio27.py

from __future__ import print_function
from multiprocessing import Process, current_process, Semaphore, Value
from random import randint

def writer(serviceQueue, resourceAccess):
	serviceQueue.acquire()
	resourceAccess.acquire()
	serviceQueue.release()

	print("{} scrive.".format(current_process().name))

	resourceAccess.release()

def reader(serviceQueue, readCount, readCountAccess, resourceAccess):
	serviceQueue.acquire()
	readCountAccess.acquire()

	if readCount.value == 0:
		resourceAccess.acquire()

	readCount.value += 1

	serviceQueue.release()
	readCountAccess.release()

	print("{} legge.".format(current_process().name))

	readCountAccess.acquire()
	readCount.value -= 1

	if readCount.value == 0:
		resourceAccess.release()

	readCountAccess.release()

if __name__ == "__main__":
	readCount = Value('i', 0)
	resourceAccess = Semaphore(1)
	readCountAccess = Semaphore(1)
	serviceQueue = Semaphore(1)

	writers = [Process(target=writer, args=(serviceQueue, resourceAccess,)) for i in range(5)]
	readers = [Process(target=reader, args=(serviceQueue, readCount, readCountAccess, resourceAccess,)) for i in range(10)]

	for w in writers:
		w.start()

	for r in readers:
		r.start()

	for w in writers:
		w.join()

	for r in readers:
		r.join()

