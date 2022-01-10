# file esercizio18.py

try:
	from tkinter import Frame, Label, Button, Menu, INSERT
	from tkinter.scrolledtext import ScrolledText
except ImportError:
	from Tkinter import Frame, Label, Button, Menu, INSERT
	from ScrolledText import ScrolledText

class Widget(Frame):
	def __init__(self, parent):
		Frame.__init__(self, master=parent, width=280, height=200)
		self.scrolledText = ScrolledText(self)
		self.scrolledText.pack()
		self.pack_propagate(False)
		self.pack()

class Esercizio18(Frame):
	def __init__(self):
		Frame.__init__(self, master=None)

		self.menubar = Menu(self)
		fileMenu = Menu(self.menubar)

		fileMenu.add_command(label="Testa", command=self.menu1ClickHandler)
		fileMenu.add_command(label="Croce", command=self.menu2ClickHandler)
		fileMenu.add_command(label="Esci", command=self.closeHandler)
		self.menubar.add_cascade(label="File", menu=fileMenu)

		self.widget = Widget(self)
		self.label = Label(self, text="Lancia la monetina con il menu a tendina.")
		self.label.pack()

		self.master.config(menu=self.menubar)

		self.pack()
		self.master.wm_title("Testa o croce?")
		self.mainloop()

	def menu1ClickHandler(self):
		self.widget.scrolledText.insert(INSERT, "Testa\n")

	def menu2ClickHandler(self):
		self.widget.scrolledText.insert(INSERT, "Croce\n")

	def closeHandler(self):
		self.master.destroy()

Esercizio18()

