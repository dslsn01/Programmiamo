# file esercizio8.py

from __future__ import print_function
from multiprocessing import Pool, Manager

def func(index, li):
	li[index] *= li[index]

if __name__ == "__main__":
	li = Manager().list([i for i in range(1, 11)])

	pool = Pool(processes=10)

	for i in range(1, 11):
		pool.apply_async(func, args=(i, li,))

	pool.close()
	pool.join()

	print(list(li))

