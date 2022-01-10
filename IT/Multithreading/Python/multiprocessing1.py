# file multiprocessing1.py

from __future__ import print_function
from multiprocessing import current_process
from time import sleep

# costrutto if necessario su Windows

if __name__ == "__main__":
	# ottiene un riferimento al processo principale dell'applicazione
	mainProcess = current_process()
	name = mainProcess.name

	# stampa il nome del processo principale
	print("Processo {}".format(name))

	# arresta il processo principale per 5 secondi
	sleep(5)

	print("Fine del processo {}.".format(current_process().name))

