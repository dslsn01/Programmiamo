# file esercizio32.py

from __future__ import print_function
if hasattr(__builtins__, 'raw_input'): input = raw_input
from sys import stdout
import os

# la classe Content rappresenta un contenuto generico: un libro, brano o video
class Content(object):
	def __init__(self, title, year):
		self.__title = title
		self.__year = year

	def getTitle(self):
		return self.__title

	def setTitle(self, title):
		self.__title = title

	def getYear(self):
		return self.__year

	def setYear(self, year):
		self.__year = year

	title = property(getTitle, setTitle)
	year = property(getYear, setYear)

class Book(Content):
	def __init__(self, title, author, year):
		Content.__init__(self, title=title, year=year)
		self.__author = author

	def getAuthor(self):
		return self.__author

	def setAuthor(self, author):
		self.__author = author

	def __str__(self):
		return "\"" + self.getTitle() + "\" (" + self.getYear() + "), di " + self.author

	author = property(getAuthor, setAuthor)

class Song(Content):
	def __init__(self, title, author, singer, year):
		Content.__init__(self, title=title, year=year)
		self.__author = author
		self.__singer = singer

	def getAuthor(self):
		return self.__author

	def setAuthor(self, author):
		self.__author = author

	def getSinger(self):
		return self.__singer

	def setSinger(self, singer):
		self.__singer = singer

	def __str__(self):
		return "\"" + self.getTitle() + "\" (" + self.getYear() + "), scritta da " + self.author + " e cantata da " + self.singer

	author = property(getAuthor, setAuthor)
	singer = property(getSinger, setSinger)

class Film(Content):
	def __init__(self, title, director, screenwriter, year):
		Content.__init__(self, title=title, year=year)
		self.__director = director
		self.__screenwriter = screenwriter

	def getDirector(self):
		return self.__director

	def setDirector(self, director):
		self.__director = director

	def getScreenwriter(self):
		return self.__screenwriter

	def setScreenwriter(self, screenwriter):
		self.__screenwriter = screenwriter

	def __str__(self):
		return "\"" + self.getTitle() + "\" (" + self.getYear() + "), diretto da " + self.director + " e sceneggiato da " + self.screenwriter

	director = property(getDirector, setDirector)
	screenwriter = property(getScreenwriter, setScreenwriter)

class Library(object):
	def __init__(self):
		self.__titles = [Book("Ulisse", "James Joyce", "1922"), Book("On the road", "Jack Kerouac", "1951"), Book("Il nome della rosa", "Umberto Eco", "1980")]
		self.__titles.extend([Film("Psycho", "Alfred Hitchcock", "Joseph Stefano", "1960"), Film("2001 Odissea nello spazio", "Stanley Kubrick", "Arthus C. Clarke", "1968"), Film("Shining", "Stanley Kubrick", "S. Kubrick & D. Johnson", "1980")])

	def loop(self):
		print("+++++++ Benvenuto nella biblioteca multimediale +++++++\nPuoi lasciare o prendere in prestito libri, musica e video.")

		self.printLib()

		while (True):
			print("a. Prendi qualcosa in prestito")
			print("b. Aggiungi un nuovo contenuto")
			print("c. Esci\n")

			opt = input()

			# salva un nuovo titolo (libro, canzone o film) nella mediateca
			if opt == "a":
				print("Cosa vuoi in prestito?")

				title = input("Titolo: ")
				f = False

				for media in self.__titles:
					if title.lower() == media.title.lower():
						f = True
						if isinstance(media, Book):
							print("Trovato il libro {}.\n".format(media))
						if isinstance(media, Song):
							print("Trovata la canzone {}.\n".format(media))
						if isinstance(media, Film):
							print("Trovato il film {}.\n".format(media))
						break

				if not f:
					print("Titolo non trovato!\n")

			# salva qualcosa di nuovo nella biblioteca
			elif opt == "b":
				print("Cosa hai portato di nuovo?\n")
				t = input("a) Un libro\nb) Un brano audio\nc) Un film / video\n\n")

				if not t in ('a', 'b', 'c'):
					print("Contenuto sconosciuto!\n")
					continue

				media = None

				title = input("Titolo: ")
				year = input("Anno: ")

				# salva un nuovo libro nella biblioteca
				if t == "a":
					author = input("Autore: ")
					media = Book(title=title, author=author, year=year)
					print("Aggiunto il libro {}.\n".format(media))

				# salva un nuovo brano audio
				if t == "b":
					author = input("Autore: ")
					singer = input("Cantante: ")
					media = Song(title=title, author=author, singer=singer, year=year)
					print("Aggiunta la canzone {}.".format(media))

				# salva un nuovo film
				if t == "c":
					director = input("Regista: ")
					screenwriter = input("Sceneggiatore: ")
					media = Film(title=title, director=director, screenwriter=screenwriter, year=year)
					print("Aggiunto il film {}.".format(media))

				self.__titles.append(media)

			elif opt == "c":
				print("Buona giornata, speriamo di rivederti presto.")
				break
			else:
				print("Opzione sconosciuta!")

	def printLib(self):
		print("Titoli disponibili:\n")
		i = 1
		for c in self.__titles:
			print("{}. {}.".format(i, c))
			i += 1
		stdout.write(os.linesep)

if __name__ == "__main__":
	mediateca = Library()
	# apre la biblioteca
	mediateca.loop()

