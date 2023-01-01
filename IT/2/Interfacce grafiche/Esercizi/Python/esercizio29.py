# file esercizio29.py

try:
	from tkinter import Frame, Label, Menu, StringVar, INSERT, END, messagebox, filedialog
	from tkinter.scrolledtext import ScrolledText, BOTH
except ImportError:
	from Tkinter import Frame, Label, Menu, StringVar, INSERT, END
	from ScrolledText import ScrolledText, BOTH
	import tkMessageBox, tkFileDialog

from os import path, getcwd, linesep
import sys
from functools import partial

class Esercizio29(Frame):
	def __init__(self, fileName=None):
		Frame.__init__(self, width=640, height=450)
		self.fileName = fileName

		self.menubar = Menu(self)
		fileMenu = Menu(self.menubar)
		self.menubar.add_cascade(label="File", menu=fileMenu)

		fileMenu.add_command(label="Nuovo", command=self.nfile)
		fileMenu.add_command(label="Apri", command=self.ofile)
		fileMenu.add_command(label="Salva", command=self.saveFile)
		fileMenu.add_command(label="Salva con nome", command=partial(self.saveFile, True))
		fileMenu.add_command(label="Esci", command=self.exit)

		self.master.config(menu=self.menubar)
		self.textArea = ScrolledText(self)
		self.vText = StringVar()
		self.vText.set("<nuovo>")
		self.label = Label(textvariable=self.vText)
		self.label.pack()
		self.textArea.pack(fill=BOTH, expand=True)

		if self.fileName:
			try:
				txt = open(self.fileName, "r").read()
				self.vText.set("\"{}\"".format(self.fileName))
				self.textArea.insert(INSERT, txt)
			except IOError as e:
				self.master.overrideredirect(True)
				self.master.withdraw()
				tkMessageBox.showwarning("Attenzione!", "Il file \"{}\" non esiste!".format(fileName))
				self.master.overrideredirect(False)
				self.master.deiconify()

		self.pack_propagate(False)
		self.pack()
		self.master.wm_title("ProgEdit")
		self.mainloop()

	# nuovo file

	def nfile(self):
		self.fileName = ""
		self.vText.set("<nuovo>")
		self.textArea.delete(1.0, END)

	# apri file

	def ofile(self):
		doc = tkFileDialog.askopenfile(initialdir=getcwd(), title="Apri nome: ", filetypes=(("text files", "*.txt"), ("all files", "*.*")))
		fileName = doc.name.split("/")[-1]
		self.fileName = fileName
		self.vText.set(fileName)
		self.textArea.delete(1.0, END)
		self.textArea.insert(INSERT, doc.read())

	# salva file: swn=Salva con nome: forza l'apertura della dialog
	def saveFile(self, swn=False):
		# file non ancora salvato
		# print swn
		if not self.fileName or swn:
			fname = tkFileDialog.asksaveasfilename(initialdir=getcwd(), title="Salva come...", filetypes=(("text files", "*.txt"), ("all files", "*.*")))
			if not fname: return
			self.fileName = fname.split("/")[-1]
			self.vText.set("\"{}\"".format(self.fileName));

		# non serve controllare se il file esiste, lo fa la libreria Tkinter
		# if path.isfile(self.fileName):
		# 	if tkMessageBox.askquestion("Attenzione!", "Il file \"{}\" esistente. Sovrascriverlo?".format(self.fileName)):
		# 		print "Uscita senza fare nulla"
		# 		return

		text = self.textArea.get(1.0, END)

		doc = open(self.fileName, "w")

		for line in text.splitlines():
			doc.write(line + linesep)
		doc.close()

		# tkMessageBox.showinfo("Avviso", "File salvato con successo!")

	def exit(self):
		self.master.destroy()

if len(sys.argv) > 1:
	fileName = sys.argv[1]
	Esercizio29(fileName)
else:
	Esercizio29()

