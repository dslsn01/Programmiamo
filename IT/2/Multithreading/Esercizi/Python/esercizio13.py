# file esercizio13.py

from __future__ import print_function
from multiprocessing import Process, current_process, Lock
from random import randint
from time import sleep

def func(lock):
	with lock:
		name = current_process().name
		print("Il processo {} entra nella funzione target.".format(name))
		sleep(5)
		print("Il processo {} esce dalla funzione target.".format(name))

if __name__ == "__main__":
	lock = Lock()

	# tra 2 e 10 processi
	nProc = randint(2, 10)
	print("Verranno creati {} processi.".format(nProc))

	procs = [Process(target=func, args=(lock,)) for i in range(nProc)]

	for p in procs:
		p.start()

	for p in procs:
		p.join()

