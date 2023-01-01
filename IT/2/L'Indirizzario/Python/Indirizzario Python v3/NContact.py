# file NContact.py

try:
	from tkinter import Toplevel, Button
except ImportError:
	from Tkinter import Toplevel, Button

from Pmw import EntryField as EntryField 

class NContact(Toplevel):
	def __init__(self, parent):
		Toplevel.__init__(self, master=parent)

		self.name = EntryField(self, value="Nome")
		self.surname = EntryField(self, value="Cognome")
		self.addr = EntryField(self, value="Indirizzo")
		self.pnum = EntryField(self, value="Numero di telefono")
		self.email = EntryField(self, value="Email")

		self.name.grid(row=0, column=0)
		self.surname.grid(row=0, column=1)
		self.addr.grid(row=1, column=0)
		self.pnum.grid(row=1, column=1)
		self.email.grid(row=2, column=0)

		ok = Button(self, text="Ok", command=self.add)
		cancel = Button(self, text="Annulla", command=self.exit)

		ok.grid(row=3, column=0)
		cancel.grid(row=3, column=1)

		self.wm_title("Inserisci contatto")

	# gestisce il click sul pulsante "Ok": inserisce i dati del nuovo contatto nel database

	def add(self):
		# recupera i dati (nome, cognome, ...) dai campi di testo 
		name = self.name.getvalue()
		surname = self.surname.getvalue()
		addr = self.addr.getvalue()
		pnum = self.pnum.getvalue()
		email = self.email.getvalue()

		cursor = self.master.conn.cursor()
		cursor.execute("INSERT INTO contacts (name, surname, addr, pnum, email) VALUES (?, ?, ?, ?, ?)", (name, surname, addr, pnum, email))

		# salva le modifiche sul database

		self.master.conn.commit()

		# invoca il metodo updateUI() per aggiornare la finestra principale  

		self.master.updateUI()
		self.destroy()

	# gestisce il click sul pulsante "Annulla": chiude la finestra

	def exit(self):
		self.destroy()

