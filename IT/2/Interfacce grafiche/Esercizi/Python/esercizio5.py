# file esercizio5.py

try:
	from tkinter import Frame
except ImportError:
	from Tkinter import Frame

frame = Frame(height=100, width=150)

frame.master.wm_title("Titolo")
frame.configure(background="red")
frame.pack()
frame.mainloop()

