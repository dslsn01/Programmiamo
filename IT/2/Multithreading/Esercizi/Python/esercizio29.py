# file esercizio29.py

from __future__ import print_function
from multiprocessing import Process, current_process, Semaphore, Value, Queue
from random import randint
from time import sleep

def barber(customers):
	p = current_process().name
	while True:
		pc = customers.get()

		print("Il barbiere {} sta tagliando i capelli al cliente {}.".format(p, pc))
		pause = randint(10, 25)
		sleep(pause)
		print("{} ha impiegato {} minuti per tagliare i capelli a {}. Avanti un altro!".format(p, pause, pc))

def customer(customers):
	p = current_process().name
	print("Il cliente {} entra nel negozio.".format(p))

	if customers.qsize() < 5:
		customers.put(p)
		print("{} si siede e aspetta di farsi tagliare i capelli...".format(p))
	else:
		print("Il cliente {} non ha trovato posto per sedersi ed esce dal negozio...".format(p))

if __name__ == "__main__":
	# coda sincronizzata tra i processi 
	customers = Queue(maxsize=5)

	pbarber = Process(target=barber, args=(customers,))

	pbarber.start()

	procs = []

	while True:
		pcustomer = Process(target=customer, args=(customers,))
		pcustomer.start()
		procs.append(pcustomer)
		pause = randint(5, 30)
		sleep(pause)

	pbarber.join()

	for c in procs:
		c.join()

