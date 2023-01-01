# file esercizio24.py

try:
	from tkinter import Frame, Canvas
except ImportError:
	from Tkinter import Frame, Canvas

frame = Frame()
canvas = Canvas(frame, height=100, width=100)

canvas.create_oval(10, 10, 90, 90, fill="green")

canvas.pack()
frame.pack()
frame.mainloop()

