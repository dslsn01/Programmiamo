# file esercizio3.py
# -*- coding: utf-8 -*-

from __future__ import print_function
from multiprocessing import current_process, Pool
from random import randint

def func():
	print(current_process().name)

if __name__ == "__main__":
	nProc = randint(2, 10)

	print("Verrà creato un pool di {} processi.".format(nProc))

	pool = Pool(processes=nProc)

	for i in range(nProc):
		pool.apply_async(func)

	pool.close()
	pool.join()

