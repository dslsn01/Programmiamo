# file eventHandling.py

try:
	from tkinter import Frame, Button, INSERT
	from tkinter.scrolledtext import ScrolledText
except ImportError:
	from Tkinter import Frame, Button, INSERT
	from ScrolledText import ScrolledText

class Widget(Frame):
	def __init__(self, parent):
		Frame.__init__(self, master=parent, width=280, height=220)

		# crea un'area di testo
		self.scrolledText = ScrolledText(self)
		self.scrolledText.pack()
		self.pack_propagate(False)
		self.pack()

class EventHandling(Frame):
	def __init__(self):
		Frame.__init__(self, master=None)
		# crea il pannello intermedio per riposizionare l'area di testo 
		self.widget = Widget(self)

		# crea un pulsante con gestore dell'evento click
		self.button = Button(self, text="Cliccami!", command=self.clickHandler)

		# visualizza le componenti grafiche
		self.button.pack()
		self.pack()
		self.master.wm_title("Ciao!")
		self.mainloop()

	def clickHandler(self):
		self.widget.scrolledText.insert(INSERT, "Click!\n")

e = EventHandling()

