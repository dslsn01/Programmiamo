# file testCopy.py

from copy import copy, deepcopy

class Student:
	def __init__(self, name, matr, cdl):
		self.name = name
		self.matr = matr
		self.cdl = cdl
		self.es = {"Architettura degli elaboratori" : -1, "Programmazione" : -1, "Calcolo 1" : -1}

	def unilib(self):
		_pass = 0
		for k, v in self.es.items():
			if v != -1:
				print("{} ({}) ha superato l'esame \"{}\" con il voto {}.".format(self.name, self.matr, k, v))
				_pass += 1

	def __str__(self):
		return "{}, matricola {}, corso di laurea in {}.".format(self.name, self.matr, self.cdl)

s1 = Student("Mario Rossi", "A23234", "Scienze dell'Informazione")
print(s1)

s2 = s1

if id(s1) == id(s2):
	print("I due studenti puntano allo stesso oggetto!")

# s2.matr = "A01357"
# print(s1)
# print(s2)

# si usa copy() per una copia superficiale, deepcopy() per la copia completa

s2 = deepcopy(s1)

if id(s1) != id(s2):
	s2.matr = "A01357"
	s2.cdl = "Ingegneria Informatica"
	s2.es["Programmazione"] = 30
	print(s1)
	print(s2)
	s1.unilib()
	s2.unilib()

