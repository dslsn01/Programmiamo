# file esercizio4.py

try:
	from tkinter import Tk, Frame, PhotoImage
except ImportError:
	from Tkinter import Frame, Label, PhotoImage

frame = Frame(height=100, width=150)

img = PhotoImage(file="img/icon.gif")

frame.tk.call("wm", "iconphoto", frame.winfo_toplevel(), img)
frame.master.wm_title("Icona")
frame.pack()
frame.mainloop()

