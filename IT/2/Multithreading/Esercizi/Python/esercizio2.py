# file esercizio2.py

from __future__ import print_function
from multiprocessing import Process, current_process
from random import randint

def func():
	print(current_process().name)

if __name__ == "__main__":
	nProc = randint(2, 10)

	print("Verranno creati {} processi.".format(nProc))

	procs = [Process(target=func) for i in range(nProc)]

	for p in procs:
		p.start()

	for p in procs:
		p.join()

