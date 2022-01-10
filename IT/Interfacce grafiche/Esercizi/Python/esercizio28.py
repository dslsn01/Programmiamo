# file esercizio28.py

try:
	from tkinter import Frame, Canvas
except ImportError:
	from Tkinter import Frame, Canvas

import random

class Esercizio28(Frame):
	def __init__(self):
		self.colors = ["red", "orange", "yellow", "green", "blue", "violet"]
		self.coords = []
		Frame.__init__(self)
		self.w = Canvas(self, width=400, height=400)
		self.w.bind("<ButtonRelease-1>", self.handler2)
		self.w.bind("<ButtonRelease-3>", self.handler3)
		self.w.pack()
		self.pack()
		self.master.wm_title("Disegna una serie di poligoni")
		self.mainloop()

	def handler2(self, e):
		self.coords.extend([e.x, e.y])

	def handler3(self, e):
		color = random.choice(self.colors)
		self.w.create_polygon(self.coords, fill=color)
		self.coords = []

Esercizio28()

