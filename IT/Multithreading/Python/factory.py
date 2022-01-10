# file factory.py

from __future__ import print_function
from multiprocessing import Pool

# classe che rappresenta una componente di un elicottero
class Part(object):
	def __init__(self, name):
		self.name = name

	def setName(self, name):
		self.__name = name

	def getName(self):
		return self.__name

	name = property(getName, setName)

# funzione che assembla una singola parte di elicottero
def assemble(name):
	return Part(name)

if __name__ == "__main__":
	t = ["elica", "motore", "carrello di atterraggio", "telaio", "parabrezza", "cloche", "sedile"]

	nProcs = len(t)
	pool = Pool(processes=nProcs)

	parts = [pool.apply_async(assemble, args=(t[i],)) for i in range(nProcs)]

	pool.close()
	pool.join()

	for p in parts:
		name = p.get().name
		print("Assemblato -> {}.".format(name))

	print("Montiamo l'elicottero pronto al decollo!")

