# file esercizio5.py
# -*- coding: utf-8 -*-

from __future__ import print_function
from multiprocessing import Pool
from random import randint

def func():
	print("Ciao, mondo!")

if __name__ == "__main__":
	nProc = randint(2, 10)

	print("Verrà creato un pool di {} processi.".format(nProc))

	pool = Pool(processes=nProc)

	for i in range(nProc):
		pool.apply_async(func)

	pool.close()
	pool.join()

