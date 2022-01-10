# file esercizio4.py

from __future__ import print_function
from multiprocessing import Process
from random import randint

def func():
	print("Ciao, mondo!")

if __name__ == "__main__":
	nProc = randint(2, 10)

	print("Verranno creati {} processi.".format(nProc))

	procs = [Process(target=func) for i in range(nProc)]

	for p in procs:
		p.start()

	for p in procs:
		p.join()

