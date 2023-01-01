# file esercizio12.py

try:
	from tkinter import Frame, Button
except ImportError:
	from Tkinter import Frame, Button

frame = Frame()

button = Button(frame, text="Click")
button.pack()

frame.pack()
frame.mainloop()

