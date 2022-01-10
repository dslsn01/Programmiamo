# file esercizio22.py
# -*- coding: utf-8 -*-

from __future__ import print_function
from multiprocessing import Process, Manager

def powerset(_set, start, end, pSet):
	bits = list(_set)
	for i in range(start, end):
		subSet = set({})
		for j in range(len(bits)):
			mask = 1 << j;
			if (i & mask) != 0:
				subSet.add(bits[j])
		powerSet.append(subSet)

if __name__ == "__main__":
	_set = {1, 2, 3}

	print(_set)

	card_pset = 1 << len(_set)
	print("Cardinalità dell'insieme potenza: {}".format(card_pset))

	nProc = card_pset // 2 # 4

	start = 0
	end = card_pset // nProc

	powerSet = Manager().list()
	procs = []

	j = 2
	for i in range(nProc):
		p = Process(target=powerset, args=(_set, start, end, powerSet,))
		procs.append(p)

		start = end
		end = j * (card_pset // nProc)
		j += 1

	for proc in procs:
		proc.start()

	for proc in procs:
		proc.join()

	print("Insieme potenza:\n{}".format(powerSet))

