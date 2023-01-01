# file esercizio28.py

from __future__ import print_function
from multiprocessing import Process, current_process, Semaphore, Value, Manager
from random import randint
from time import sleep

def barber(barberReady, accessWRSeats, customerReady, numberOfFreeWRSeats, customers):
	p = current_process().name
	while True:
		customerReady.acquire()
		accessWRSeats.acquire()

		pc = customers[numberOfFreeWRSeats.value]
		numberOfFreeWRSeats.value += 1
		barberReady.release()
		accessWRSeats.release()

		print("Il barbiere {} sta tagliando i capelli al cliente {}.".format(p, pc))
		pause = randint(10, 25)
		sleep(pause)
		print("{} ha impiegato {} minuti per tagliare i capelli a {}. Avanti un altro!".format(p, pause, pc))

def customer(barberReady, accessWRSeats, customerReady, numberOfFreeWRSeats, customers):
	p = current_process().name
	print("Il cliente {} entra nel negozio.".format(p))

	accessWRSeats.acquire()
	if numberOfFreeWRSeats.value > 0:
		numberOfFreeWRSeats.value -= 1
		customers[numberOfFreeWRSeats.value] = p
		print("{} si siede e aspetta di farsi tagliare i capelli...".format(p))
		customerReady.release()
		accessWRSeats.release()
		barberReady.acquire()
	else:
		print("Il cliente {} non ha trovato posto per sedersi ed esce dal negozio...".format(p))
		accessWRSeats.release()

if __name__ == "__main__":
	barberReady = Semaphore(0)
	accessWRSeats = Semaphore(1)
	customerReady = Semaphore(0)
	numberOfFreeWRSeats = Value('i', 5)

	# lista condivisa tra i processi tramite un manager
	customers = Manager().list([""]*5)

	pbarber = Process(target=barber, args=(barberReady, accessWRSeats, customerReady, numberOfFreeWRSeats, customers,))

	pbarber.start()

	procs = []

	while True:
		pcustomer = Process(target=customer, args=(barberReady, accessWRSeats, customerReady, numberOfFreeWRSeats, customers,))
		pcustomer.start()
		procs.append(pcustomer)
		pause = randint(5, 30)
		sleep(pause)

	pbarber.join()

	for c in procs:
		c.join()

