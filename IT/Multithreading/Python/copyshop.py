# file copyshop.py

from __future__ import print_function
from multiprocessing import Process, current_process, Semaphore, Lock
from random import randint
from time import sleep

def printingJob(document, printer, lock):
	# documento inviato in un intervallo di tempo tra 1 e 25 secondi
	pause = randint(1, 25)
	sleep(pause)

	with lock:
		print("{} invia il documento \"{}\" alla stampante.".format(current_process().name, document))

	# acquisisce il semaforo-stampante
	printer.acquire()

	pause = randint(5, 10)
	sleep(pause)
	print("Stampato il documento \"{}\" inviato dal {}.".format(document, current_process().name))

	# libera il semaforo-stampante
	printer.release()

if __name__ == "__main__":
	# il semaforo rappresenta una stampante condivisa
	printer = Semaphore(1)
	lock = Lock()

	documents = ["Modulo di iscrizione", "Appunti d'esame", "Tesi laurea triennale", "Tesi laurea specialistica", "Tesi dottorato"]

	students = [Process(target=printingJob, args=(documents[randint(0, len(documents)-1)], printer, lock,)) for i in range(10)]

	for student in students:
		student.start()

	for student in students:
		student.join()

