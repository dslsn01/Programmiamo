# file esercizio20.py

from __future__ import print_function

# la classe Employee rappresenta un'impiegato di un'azienda

class Employee(object):
	# identifichiamo ogni impiegato da nome, cognome e numero di badge
	def __init__(self, name, surname, badge):
		self.__name = name
		self.__surname = surname
		self.__badge = badge

	def setName(self, name):
		self.__name = name

	def getName(self):
		return self.__name

	def setSurname(self, surname):
		self.__surname = surname

	def getSurname(self):
		return self.__surname

	def setBadge(self, badge):
		self.__badge = badge

	def getBadge(self):
		return self.__badge

	name = property(getName, setName)
	surname = property(getSurname, setSurname)
	badge = property(getBadge, setBadge)

	# il metodo __str__ stampa nome, cognome e bagde dell'impiegato corrente
	def __str__(self):
		return "{} {}, badge numero={}".format(self.name, self.surname, self.badge)

	# due impiegati sono uguali se e solo se hanno lo stesso badge, quindi sono la stessa persona

	def __eq__(self, other):
		if not isinstance(other, Employee):
			return False

		return (self.badge == other.badge)

	# il metodo __hash__() restituisce l'hash della tupla che contiene le variabili membro

	def __hash__(self):
		# calcola l'hash complessivo di tutte le variabili membro, e moltiplica il risultato per una costante prima
		prime = 31
		result = 1
		result = prime * result + hash((self.name, self.surname, self.badge))
		return result

emp1 = Employee(name="Mario", surname="Rossi", badge=12345)
emp2 = Employee(name="Luigi", surname="Bianchi", badge=56789)
emp3 = Employee(name="Luigi", surname="Bianchi", badge=56789)

print(emp1)
print(emp2)
print(emp3)

print("Il primo e il secondo impiegato sono la stessa persona?", emp1 == emp2)
print("Il secondo e il terzo impiegato sono la stessa persona?", emp2 == emp3)

