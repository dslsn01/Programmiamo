# file esercizio7.py

try:
	from tkinter import Frame, Label
except ImportError:
	from Tkinter import Frame, Label

frame = Frame()

label1 = Label(frame, text="Un'etichetta")
label2 = Label(frame, text="Un'altra etichetta")

label1.pack()
label2.pack()

frame.pack()
frame.mainloop()

