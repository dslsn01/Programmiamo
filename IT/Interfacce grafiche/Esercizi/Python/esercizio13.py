# file esercizio13.py

try:
	from tkinter import Frame, Button
except ImportError:
	from Tkinter import Frame, Button

class Esercizio13(Frame):
	def __init__(self):
		Frame.__init__(self)
		self.button = Button(self, text="Chiudi", command=self.close)
		self.button.pack()
		self.pack()
		self.mainloop()

	def close(self):
		self.master.destroy()

Esercizio13()

