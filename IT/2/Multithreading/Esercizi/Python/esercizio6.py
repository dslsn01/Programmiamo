# file esercizio6.py

from __future__ import print_function
from multiprocessing import Process, Manager

def func(index, li):
	li[index] *= 2

if __name__ == "__main__":
	li = Manager().list([i for i in range(1, 11)])

	procs = [Process(target=func, args=(i, li,)) for i in range(10)]

	for p in procs:
		p.start()

	for p in procs:
		p.join()

	print(list(li))

