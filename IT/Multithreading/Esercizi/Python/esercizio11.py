# file esercizio11.py

from __future__ import print_function
from multiprocessing import Process, RawArray
from sys import stdout
from os import linesep

def target(v, value, pos):
	v[pos] *= value

if __name__ == "__main__":
	# x, y, z
	v = RawArray('f', [1.0, 2.0, 3.0])

	for coord in v:
		print(coord, end=" ")

	stdout.write(linesep)

	scalar = 2.0

	procs = [Process(target=target, args=(v, scalar, i,)) for i in range(0, 3)]

	for p in procs:
		p.start()

	for p in procs:
		p.join()

	for coord in v:
		print(coord, end=" ")

	stdout.write(linesep)

