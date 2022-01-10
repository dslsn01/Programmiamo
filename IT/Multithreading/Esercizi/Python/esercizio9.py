# file esercizio9.py

from __future__ import print_function
from multiprocessing import Pool

def func(index):
	k = 1
	row = [index for i in range(10)]
	for i in range(10):
		row[i] *= k
		k += 1
	return row

if __name__ == "__main__":
	pool = Pool(processes=10)
	tbp = [pool.apply_async(func, args=(i,)) for i in range(1, 11)]

	pool.close()
	pool.join()

	for row in tbp:
		print(row.get())

