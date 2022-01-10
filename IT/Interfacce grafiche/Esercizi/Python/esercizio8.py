# file esercizio8.py

try:
	from tkinter import Frame, Label, LEFT
except ImportError:
	from Tkinter import Frame, Label, LEFT

frame = Frame()

label1 = Label(frame, text="Un'etichetta")
label2 = Label(frame, text="Un'altra etichetta")

label1.pack(side=LEFT)
label2.pack(side=LEFT)

frame.pack()
frame.mainloop()

