# file esercizio31.py

from __future__ import print_function
if hasattr(__builtins__, 'raw_input'): input = raw_input
from sys import stdout
import os

# la classe Book rappresenta un libro
class Book(object):
	def __init__(self, title, author, year):
		self.__title = title
		self.__author = author
		self.__year = year

	def getTitle(self):
		return self.__title

	def setTitle(self, title):
		self.__title = title

	def getAuthor(self):
		return self.__author

	def setAuthor(self, author):
		self.__author = author

	def getYear(self):
		return self.__year

	def setYear(self, year):
		self.__year = year

	def __str__(self):
		return "\"" + self.title + "\" (" + self.year + "), di " + self.author

	title = property(getTitle, setTitle)
	author = property(getAuthor, setAuthor)
	year = property(getYear, setYear)

class Library(object):
	def __init__(self):
		self.__titles = [Book("Ulisse", "James Joyce", "1922"), Book("On the road", "Jack Kerouac", "1951"), Book("Il nome della rosa", "Umberto Eco", "1980")]

	def loop(self):
		print("+++++++ Benvenuto in biblioteca +++++++")

		self.printLib()

		while (True):
			print("a. Prendi un libro in prestito")
			print("b. Aggiungi un nuovo libro")
			print("c. Esci\n")

			opt = input()

			# prende un libro in prestito
			if opt == "a":
				print("Prendi un libro in prestito.")

				title = input("Titolo: ")
				f = False

				for book in self.__titles:
					if title.lower() == book.title.lower():
						print("Trovato il libro {}.\n".format(book))
						f = True
						break

				if not f:
					print("Libro non trovato!\n")

			# salva un nuovo libro nella biblioteca
			elif opt == "b":
				print("Aggiungi un nuovo libro.")

				title = input("Titolo: ")
				author = input("Autore: ")
				year = input("Anno: ")

				book = Book(title=title, author=author, year=year)
				self.__titles.append(book)

				print("Aggiunto il libro {}.\n".format(book))
				self.printLib()

			elif opt == "c":
				print("Buona lettura, speriamo di rivederti presto.")
				break
			else:
				print("Opzione sconosciuta!")

	def printLib(self):
		print("Libri disponibili:\n")
		i = 1
		for b in self.__titles:
			print("{}. {}.".format(i, b))
			i += 1
		stdout.write(os.linesep)

if __name__ == "__main__":
	library = Library()
	# apre la biblioteca
	library.loop()

