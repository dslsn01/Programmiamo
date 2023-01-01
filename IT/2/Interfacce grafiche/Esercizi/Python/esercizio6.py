# file esercizio6.py

try:
	from tkinter import Frame, Label
except ImportError:
	from Tkinter import Frame, Label

frame = Frame()

label = Label(frame, text="La tua stringa")
label.pack()

frame.pack()
frame.mainloop()

