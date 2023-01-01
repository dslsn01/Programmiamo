# file esercizio26.py

from __future__ import print_function
from multiprocessing import Process, current_process, Semaphore, Lock, Manager
from random import randint
from time import sleep

def producer(fill, empty, buffLock, buff):
	p = current_process().name

	while True:
		item = "pacco regalo"

		empty.acquire()
		buffLock.acquire()
		# aggiunge un nuovo pacco regalo sullo scaffale
		buff.put(item)
		buffLock.release()

		print("{} prepara un pacco regalo ({} disponibili).".format(p, buff.qsize()))
		fill.release()

		pause = randint(1, 25)
		sleep(pause)

def consumer(fill, empty, buffLock, buff):
	p = current_process().name
	while True:
		fill.acquire()
		buffLock.acquire()
		# preleva un pacco regalo dallo scaffale
		item = buff.get()
		buffLock.release()

		print("{} acquista un {} ({} rimanenti).".format(p, item, buff.qsize()))
		empty.release()

		pause = randint(1, 25)
		sleep(pause)

if __name__ == "__main__":
	buff = Manager().Queue(maxsize=5)
	buffLock = Lock()
	fill = Semaphore(0)
	empty = Semaphore(25)

	pProducer = Process(target=producer, args=(fill, empty, buffLock, buff,))
	pProducer.start()

	pConsumer = Process(target=consumer, args=(fill, empty, buffLock, buff,))
	pConsumer.start()

	pProducer.join()
	pConsumer.join()

