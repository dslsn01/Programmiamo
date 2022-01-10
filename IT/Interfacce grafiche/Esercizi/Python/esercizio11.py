# file esercizio11.py

try:
	from tkinter import Frame
except ImportError:
	from Tkinter import Frame

class Esercizio11(Frame):
	def __init__(self):
		Frame.__init__(self, height=100, width=150)
		self.master.wm_title("Titolo")
		self.pack()
		self.mainloop()

Esercizio11()

