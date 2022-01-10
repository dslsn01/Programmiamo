# file esercizio14.py

try:
	from tkinter import Frame, Button, messagebox
except ImportError:
	from Tkinter import Frame, Button
	import tkMessageBox as messagebox

class Esercizio14(Frame):
	def __init__(self):
		Frame.__init__(self)
		self.Button = Button(self, text="Aiuto", command=self.showPopUp)
		self.Button.pack()
		self.tk.eval("tk::PlaceWindow . center")
		self.pack()
		self.mainloop()

	def showPopUp(self):
		messagebox.showinfo("Alert", "Hai chiesto aiuto!")

Esercizio14()
