# file graphicHelloWorld.py

# supporto per Python 2 e Python 3
try:
	from tkinter import Frame, Label
except ImportError:
	from Tkinter import Frame, Label

# crea la finestra principale

frame = Frame()

# crea un'etichetta di testo

label = Label(frame, text="Ciao, mondo!")

# visualizza l'etichetta

label.pack()

# visualizza la finestra principale

frame.pack()

# inizia il ciclo di vita dell'applicazione

frame.mainloop()

