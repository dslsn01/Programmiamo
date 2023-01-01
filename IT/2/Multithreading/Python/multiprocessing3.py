# file multiprocessing3.py

from __future__ import print_function
from multiprocessing import Process, current_process
import time
from random import randint

def selectFromDb():
	pName = current_process().name
	print("{} - selezione database".format(pName))
	for i in range(3):
		print("{} - elaborazione dati...".format(pName))
		# pausa da 1 a 3 secondi
		time.sleep(randint(1, 3))

def mainFunc():
	for i in range(3):
		print("{} - ciclo principale".format(current_process().name))
		# pausa da 1 a 3 secondi
		time.sleep(randint(1, 3))

# costrutto if necessario su Windows

if __name__ == "__main__":
	# crea due nuovi processi

	p1 = Process(target=mainFunc, name="MAIN")
	p2 = Process(target=selectFromDb, name="BACKGROUND")

	# abilita i nuovi processi

	p1.start()
	p2.start()

	p1.join()
	p2.join()

	print("Dati dal database pronti all'uso!")

