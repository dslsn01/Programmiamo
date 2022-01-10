# file esercizio17.py

try:
	from tkinter import Frame, Button, Menu, INSERT
	from tkinter.scrolledtext import ScrolledText
except ImportError:
	from Tkinter import Frame, Button, Menu, INSERT
	from ScrolledText import ScrolledText

class Widget(Frame):
	def __init__(self, parent):
		Frame.__init__(self, master=parent, width=280, height=170)
		self.scrolledText = ScrolledText(self)
		self.scrolledText.pack()
		self.pack_propagate(False)
		self.pack()

class Esercizio17(Frame):
	def __init__(self):
		Frame.__init__(self, master=None)

		self.menubar = Menu(self)
		fileMenu = Menu(self.menubar)
		fileMenu.add_command(label="Esci", command=self.closeHandler)
		self.menubar.add_cascade(label="File", menu=fileMenu)

		self.widget = Widget(self)
		self.button1 = Button(self, text="Testa", command=self.btn1ClickHandler)
		self.button1.pack()
		self.button2 = Button(self, text="Croce", command=self.btn2ClickHandler)
		self.button2.pack()

		self.master.config(menu=self.menubar)
		self.pack()
		self.master.wm_title("Testa o croce?")
		self.mainloop()

	def btn1ClickHandler(self):
		self.widget.scrolledText.insert(INSERT, "Testa\n")

	def btn2ClickHandler(self):
		self.widget.scrolledText.insert(INSERT, "Croce\n")

	def closeHandler(self):
		self.master.destroy()

Esercizio17()

