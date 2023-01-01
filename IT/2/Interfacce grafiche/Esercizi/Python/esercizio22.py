# file esercizio22.py

try:
	from tkinter import Frame, Label
except ImportError:
	from Tkinter import Frame, Label

class Esercizio22(Frame):
	def __init__(self):
		Frame.__init__(self, height=50, width=200)
		self.coords = Label(self, text="x = -1, y = -1")
		self.coords.pack()
		self.bind("<Motion>", self.mouseMoved)
		self.pack_propagate(False)
		self.pack()
		self.mainloop()

	def mouseMoved(self, event):
		x, y = event.x, event.y
		self.coords.configure(text="x = {}, y = {}".format(x, y))

Esercizio22()

