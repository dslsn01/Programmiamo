# file esercizio19.py

try:
	from tkinter import Frame, Label
	from tkinter.ttk import Combobox
except ImportError:
	from Tkinter import Frame, Label
	from ttk import Combobox

class Esercizio19(Frame):
	def __init__(self):
		Frame.__init__(self, height=50, width=200)
		self.label = Label(self, text="Ciao!")
		self.label.pack()
		self.lang = Combobox(self, values=("inglese", "italiano"), state="readonly")
		self.lang.set("italiano")
		self.lang.pack()
		self.lang.bind("<<ComboboxSelected>>", self.onSelectItem)
		self.pack_propagate(False)
		self.pack()
		self.master.wm_title("Scegli la tua lingua")
		self.mainloop()

	def onSelectItem(self, event=None):
		lang = event.widget.get()

		if lang == "italiano":
			self.label.configure(text="Ciao!")

		if lang == "inglese":
			self.label.configure(text="Hello!")

Esercizio19()

