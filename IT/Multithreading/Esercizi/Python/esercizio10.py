# file esercizio10.py

from __future__ import print_function
from multiprocessing import Process, RawArray
from sys import stdout
from os import linesep

def target(arr, start, end):
	for i in range(start, end):
		arr[i] = i+1

if __name__ == "__main__":
	arr = RawArray('i', [0]*9)

	for i in arr:
		print(i, end=" ")

	stdout.write(linesep)

	procs = [Process(target=target, args=(arr, i, i+3,)) for i in range(0, 9, 3)]

	for p in procs:
		p.start()

	for p in procs:
		p.join()

	for i in arr:
		print(i, end=" ")

	stdout.write(linesep)

