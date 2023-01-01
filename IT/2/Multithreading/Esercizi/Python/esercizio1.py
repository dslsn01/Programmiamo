# file esercizio1.py

from __future__ import print_function
from multiprocessing import Process, current_process
from time import sleep

def func():
	pName = current_process().name
	print("Inizio del processo {}.".format(pName))
	sleep(5)
	print("Fine del processo {}.".format(pName))

if __name__ == "__main__":
	main = current_process().name
	print("Processo {}".format(main))

	p = Process(target=func)

	p.start()
	p.join()

	print("Fine del processo {}.".format(main))

