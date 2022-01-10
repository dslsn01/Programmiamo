# file esercizio27.py

try:
	from tkinter import Frame, Canvas
except ImportError:
	from Tkinter import Frame, Canvas

import math

class Esercizio27(Frame):
	def __init__(self):
		self.x0 = -1.0
		self.x0 = -1.0
		Frame.__init__(self)
		self.w = Canvas(self, width=400, height=400)
		self.w.bind("<Button-1>", self.mousePressed)
		self.w.bind("<ButtonRelease-1>", self.mouseReleased)
		self.w.pack()
		self.pack()
		self.mainloop()

	def mousePressed(self, e):
		self.x0 = e.x
		self.y0 = e.y

	def mouseReleased(self, e):
		# raggio della circonferenza
		r = math.sqrt(math.pow(e.x - self.x0, 2.0) + math.pow(e.y - self.y0, 2))
		_x0 = self.x0 - r
		_y0 = self.y0 - r
		self.w.create_oval(_x0, _y0, _x0 + r*2, _y0 + r*2)

Esercizio27()

