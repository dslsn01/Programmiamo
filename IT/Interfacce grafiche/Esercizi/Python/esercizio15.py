# file esercizio15.py

try:
	from tkinter import Frame, Menu
except ImportError:
	from Tkinter import Frame, Menu

class Esercizio15(Frame):
	def __init__(self):
		Frame.__init__(self, width=50)

		self.menubar = Menu(self)
		fileMenu = Menu(self.menubar)
		self.menubar.add_cascade(label="File", menu=fileMenu)
		fileMenu.add_command(label="Esci", command=self.closeHandler)

		self.master.config(menu=self.menubar)
		self.pack()
		self.mainloop()

	def closeHandler(self):
		self.master.destroy()

Esercizio15()

