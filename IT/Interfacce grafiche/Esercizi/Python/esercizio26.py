# file esercizio26.py

try:
	from tkinter import Frame, Canvas
except ImportError:
	from Tkinter import Frame, Canvas

import math

class Esercizio26(Frame):
	def addPolygon(self, width, height, nVertx):
		r = width / 2
		x0 = r
		y0 = height / 2
		coords = []
		thetaI = 2 * math.pi / nVertx;
		theta = thetaI if not nVertx % 2 else -math.pi / 2
		for i in range(nVertx):
			x = x0 + r * math.cos(theta)
			y = y0 + r * math.sin(theta)
			coords.extend([x, y])
			theta += thetaI

		self.ngons.append(coords)

	def __init__(self):
		Frame.__init__(self)
		self.ngons = []
		w = 400
		h = 400
		self.w = Canvas(self, width=w, height=h)

		for i in range(3, 13):
			self.addPolygon(w, h, i)

		for ngon in self.ngons:
			self.w.create_polygon(ngon, outline="black", fill="")

		self.w.pack()
		self.pack()
		self.mainloop()

Esercizio26()

