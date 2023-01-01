# file multiprocessing2.py

from __future__ import print_function
from multiprocessing import Process, current_process

def func():
	print("Ciao, sono il {}!".format(current_process().name))

# costrutto if necessario su Windows

if __name__ == "__main__":
	# crea due nuovi processi

	p1 = Process(target=func)
	p2 = Process(target=func)

	# abilita i nuovi processi

	p1.start()
	p2.start()
	
	p1.join()
	p2.join()

