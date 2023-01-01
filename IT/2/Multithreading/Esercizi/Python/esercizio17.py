# file esercizio17.py

from __future__ import print_function
from multiprocessing import Process, current_process, Semaphore, Lock
from random import randint
from time import sleep

def car(semaphore, lock):
	auto = current_process().name

	# andatura dell'auto compresa tra 45 e 90 km orari
	speed = randint(45, 90)
	with lock:
		print("L'auto {} viaggia a {} km/h...".format(auto, speed))

	pause = randint(3, 5)
	sleep(pause)

	c = semaphore.acquire()
	# print "{}, c={}".format(auto, c)
	# if c == True:
	with lock:
		print("{} attraversa l'incrocio.".format(auto))

	semaphore.release()
	# else:
	#	print "L'auto {} si ferma in coda".format(auto)

if __name__ == "__main__":
	semaphore = Semaphore(3)
	lock = Lock()

	auto = [Process(target=car, args=(semaphore, lock,)) for i in range(25)]

	for p in auto:
		p.start()
		pause = randint(0, 1)
		sleep(pause)

	for p in auto:
		p.join()

