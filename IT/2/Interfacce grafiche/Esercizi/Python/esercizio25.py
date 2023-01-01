# file esercizio25.py

try:
	from tkinter import Frame, Canvas
except ImportError:
	from Tkinter import Frame, Canvas

frame = Frame()
canvas = Canvas(frame, height=100, width=100)

canvas.create_oval(10, 10, 90, 90, fill="red")
canvas.create_oval(20, 20, 80, 80, fill="green")
canvas.create_oval(30, 30, 70, 70, fill="blue")

canvas.pack()
frame.pack()
frame.mainloop()

