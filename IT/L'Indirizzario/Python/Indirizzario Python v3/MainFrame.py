# file MainFrame.py

try:
	from tkinter import Frame, Menu
except ImportError:
	from Tkinter import Frame, Menu

from Pmw import NoteBook
from Contact import * 
from NContact import *
import sqlite3

class MainFrame(Frame):
	def __init__(self):
		Frame.__init__(self, height=480, width=640, master=None)

		# crea il Notebook

		self.tabbedPane = NoteBook(self)

		self.conn = sqlite3.connect("addrb.db")
		cursor = self.conn.cursor()

		cursor.execute("CREATE TABLE IF NOT EXISTS contacts (id INTEGER PRIMARY KEY, name VARCHAR, surname VARCHAR, addr VARCHAR, pnum VARCHAR, email VARCHAR, CHECK(LENGTH(pnum <= 15)))")

		# salva (eventuali) modifiche al database

		self.conn.commit()

		self.updateUI()

		# crea un nuovo menu

		menubar = Menu(self)
		fileMenu = Menu(menubar)
		menubar.add_cascade(label="file", menu=fileMenu)

		# aggiunge tre sottomenu al menu "file", associando a ciascuno il relativo gestore degli eventi

		fileMenu.add_command(label="Nuovo", command=self.save)
		fileMenu.add_command(label="Cancella", command=self.remove)
		fileMenu.add_command(label="Esci", command=self.exit)

		# imposta la barra dei menu

		self.master.config(menu=menubar)

		self.tabbedPane.pack(fill='both', expand=True)

		self.pack_propagate(False)
		self.pack()
		self.master.wm_title("Indirizzario")

	# il metodo save() gestisce il click sul menu "Nuovo"

	def save(self):
		NContact(self)

	# il metodo remove() gestisce il click sul menu "Cancella"

	def remove(self):
		pageName = self.tabbedPane.getcurselection()
		index = self.tabbedPane.index(pageName)
		tab = self.tabbedPane.page(index)

		# recupera il pannello Contact associato alla linguetta con il "monkey patching" 

		contact = tab.contact

		name = contact.name.__getitem__("text")
		surname = contact.surname.__getitem__("text")

		# cancella il contatto dal database

		cursor = self.conn.cursor()
		cursor.execute("DELETE FROM contacts WHERE name = ? AND surname = ?", (name, surname))

		# salva le modifiche sul database

		self.conn.commit()
		self.updateUI()

	# il metodo exit() gestisce il click sul menu "Esci"

	def exit(self): 
		self.master.destroy()

	# crea le linguette dei contatti nel Notebook

	def updateUI(self):
		self.deleteTabs()
		cursor = self.conn.cursor()
		cursor.execute("SELECT name, surname, addr, pnum, email FROM contacts")

		i = 1
		for row in cursor:
			pageName = "{} - {} {}".format(i, row[0], row[1])
			tab = self.tabbedPane.add(pageName)
			contact = Contact(parent=tab, name=row[0], surname=row[1], addr=row[2], pnum=row[3], email=row[4]) 

			# utilizza il "monkey patching" per aggiungere un contatto alla linguetta

			tab.contact = contact
			i += 1

	# cancella tutte le linguette nel NoteBook

	def deleteTabs(self):
		for page in self.tabbedPane.pagenames():
			self.tabbedPane.delete(page)

