# file esercizio21.py

try:
	from tkinter import Frame
except ImportError:
	from Tkinter import Frame

class Esercizio21(Frame):
	def __init__(self):
		Frame.__init__(self, height=100, width=150)
		self.default = self.cget("background")
		self.bind("<Enter>", self.enterEvent)
		self.bind("<Leave>", self.leaveEvent)
		self.pack()
		self.mainloop()

	def enterEvent(self, event=None):
		self.config(bg="green")

	def leaveEvent(self, event=None):
		self.config(bg=self.default)

Esercizio21()

