# file esercizio25.py

from __future__ import print_function
from multiprocessing import Process, current_process, Semaphore
from random import randint
from time import sleep

def philosopher(forks, rIndex, lIndex):
	t = current_process().name
	while True:
		if forks[rIndex].acquire(False):
			if forks[lIndex].acquire(False):
				print("{} prende le forchette {} e {}.".format(t, rIndex, lIndex))
				print("{} sta mangiando.".format(t))

				# ogni filosofo impiega tra 4 e 8 secondi per mangiare
				pause = randint(4, 8)
				sleep(pause)

				print("{} posa le forchette {} e {}.".format(t, rIndex, lIndex))

				forks[lIndex].release()
			forks[rIndex].release()

		# ogni filosofo pensa per 3/5 minuti
		pause = randint(3, 5)
		sleep(pause)
		print("{} sta pensando...".format(t))

if __name__ == "__main__":
	N_PHILOSOPHERS = 5
	names = ["Platone", "Pitagora", "Kant", "Leibniz", "Marx"]
	forks = [Semaphore(1) for i in range(N_PHILOSOPHERS)]
	procs = [Process(target=philosopher, args=(forks, i, (i+1) % N_PHILOSOPHERS,), name=names[i]) for i in range(N_PHILOSOPHERS)]

	for ph in procs:
		ph.start()

	for ph in procs:
		ph.join()

