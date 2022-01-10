# file esercizio9.py
# passare un parametro da linea di comando, per esempio
# python esercizio9.py 'Ciao, mondo!' (Attenzione ai singoli apici) 

import sys

try:
	from tkinter import Frame, Label
except ImportError:
	from Tkinter import Frame, Label

arg = sys.argv[1] if len(sys.argv) > 1 else "La tua stringa"

frame = Frame()

label = Label(frame, text=arg)
label.pack()

frame.pack()
frame.mainloop()

