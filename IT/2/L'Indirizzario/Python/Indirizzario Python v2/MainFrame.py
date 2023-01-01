# file MainFrame.py

try:
	from tkinter import Frame, Menu
except ImportError:
	from Tkinter import Frame, Menu

from Pmw import NoteBook
from Contact import * 
from NContact import *

class MainFrame(Frame):
	def __init__(self):
		Frame.__init__(self, height=480, width=640, master=None)

		# crea il Notebook

		self.tabbedPane = NoteBook(self)
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
		pass

	# il metodo exit() gestisce il click sul menu "Esci"

	def exit(self): 
		self.master.destroy()

	# crea le linguette dei contatti (fittizi) nel Notebook

	def updateUI(self):
		for counter in range(1,4):
			pageName = "Pagina {}".format(counter)
			tab = self.tabbedPane.add(pageName)
			Contact(parent=tab, name="Nome", surname="Cognome", addr="Indirizzo", pnum="Telefono", email="E-mail")

