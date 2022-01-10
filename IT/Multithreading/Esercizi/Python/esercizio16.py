# file esercizio16.py

from multiprocessing import Process, Value, Lock
from time import sleep
from sys import stdout
from os import linesep

def func(v, lock):
	lock.acquire()

	for i in range(3):
		v.value += 1
		stdout.write("{} ".format(v.value))
		stdout.flush() # flush necessario!
		sleep(1)

	lock.release()

if __name__ == "__main__":
	lock = Lock()
	v = Value('i', 0)

	procs = [Process(target=func, args=(v, lock)) for i in range(3)]

	for p in procs:
		p.start()

	for p in procs:
		p.join()

	stdout.write(linesep)

