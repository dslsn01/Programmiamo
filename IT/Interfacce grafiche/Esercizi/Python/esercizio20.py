# file esercizio20.py

try:
	from tkinter import Frame, Label
	from tkinter.ttk import Combobox
except ImportError:
	from Tkinter import Frame, Label
	from ttk import Combobox

class Esercizio20(Frame):
	def __init__(self):
		Frame.__init__(self, height=50, width=200)
		self.default = self.cget("background")
		self.color = Combobox(self, values=("default", "rosso", "verde", "blu"), state="readonly")
		self.color.set("default")
		self.color.pack()
		self.color.bind("<<ComboboxSelected>>", self.onSelectItem)
		self.pack_propagate(False)
		self.pack()
		self.master.wm_title("Scegli il colore")
		self.mainloop()

	def onSelectItem(self, event=None):
		color = event.widget.get()

		if color == "default":
			self.config(bg=self.default)

		if color == "rosso":
			self.config(bg="red")

		if color == "verde":
			self.config(bg="green")

		if color == "blu":
			self.config(bg="blue")

Esercizio20()

