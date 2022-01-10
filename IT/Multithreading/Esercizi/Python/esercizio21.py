# file esercizio21.py

from __future__ import print_function
from multiprocessing import Process, current_process, Manager
import math
from time import time
if hasattr(__builtins__, 'raw_input'): input = raw_input

def sieve(numbers, primes):
	for n in numbers:
		isPrime = True
		for i in range(2, int(math.floor(math.sqrt(n)))+1):
			if n % i == 0:
				isPrime = False
				break
		if isPrime:
			primes.append(n)

def chunks(numbers, interval):
	# print "chunks: len(numbers) = {}, numbers={}".format(len(numbers), numbers)
	for i in range(0, len(numbers), interval):
		yield numbers[i:i+interval]

if __name__ == "__main__":
	n = 0
	while n < 2:
		try:
			n = int(input("Inserisci un numero naturale >= 2: "))
		except ValueError:
			print("Numero non valido!")

	N = n-1 # escludiamo 1 (non primo per definizione)

	nProc = 4 if n > 8 else 1
	lSection = N // nProc
	if (N % nProc) > 0: nProc += 1

	splitList = list(chunks(tuple(range(2, n+1)), lSection))

	primes = Manager().list()
	procs = [Process(target=sieve, args=(splitList[jobId], primes,)) for jobId in range(nProc)]

	startT = int(round(time()*1000))

	for proc in procs:
		proc.start()

	for proc in procs:
		proc.join()

	endT = int(round(time()*1000))

	# tempo totale in millisecondi
	print("Tempo totale: {} millisecondi.".format(endT - startT))

	nPrimes = len(primes)
	print("Ci sono {} numeri primi minori o uguali a {}.".format(nPrimes, n))

	if nPrimes <= 100:
		primes.sort()
		print(primes)

