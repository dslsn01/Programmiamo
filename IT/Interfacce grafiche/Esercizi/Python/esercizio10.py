# file esercizio10.py

try:
	from tkinter import Frame, Label, PhotoImage
except ImportError:
	from Tkinter import Frame, Label, PhotoImage

frame = Frame()

img = PhotoImage(file="img/image.gif")
background = Label(frame, image=img)
background.place(x=0, y=0, relwidth=1, relheight=1)
background.pack()

frame.master.wm_title("Immagine")
frame.pack()
frame.mainloop()

