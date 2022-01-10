# file Contact.py

try:
	from tkinter import Frame, Label
except ImportError:
	from Tkinter import Frame, Label

class Contact(Frame):
	def __init__(self, parent, name, surname, addr, pnum, email): 
		Frame.__init__(self, master=parent)

		# gestisce la dimensione delle celle
		# altezza delle righe

		self.rowconfigure(0, minsize=150)
		self.rowconfigure(1, minsize=150)
		self.rowconfigure(2, minsize=150)

		# larghezza delle colonne

		self.columnconfigure(0, minsize=350)
		self.columnconfigure(1, minsize=350)

		self.name = Label(self, text=name)
		self.surname = Label(self, text=surname)
		self.addr = Label(self, text=addr)
		self.pnum =  Label(self, text=pnum)
		self.email = Label(self, text=email)
  
		self.name.grid(row=0, column=0)
		self.surname.grid(row=0, column=1)
		self.addr.grid(row=1, column=0)
		self.pnum.grid(row=1, column=1)
		self.email.grid(row=2, column=0)

		self.grid()

