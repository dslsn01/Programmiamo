# file wildWildWest.py

from __future__ import print_function
from multiprocessing import Process, current_process, Lock
import time
from random import randint

def tieCows(lock):
	with lock:
		for i in range(3):
			print("Il cowboy {} sta chiudendo le sue mucche nella stalla...".format(current_process().name))
			time.sleep(randint(1, 3))

if __name__ == "__main__":
	lock = Lock()

	p1 = Process(target=tieCows, args=(lock,), name="Wyatt Earp")
	p2 = Process(target=tieCows, args=(lock,), name="Buffalo Bill")

	p1.start()
	p2.start()

	p1.join()
	p2.join()

