# file esercizio1.py

try:
	from tkinter import Frame
except ImportError:
	from Tkinter import Frame

frame = Frame(height=100, width=150)

frame.pack()
# frame.master.geometry("50x50")
frame.master.update_idletasks()

# "100x100"
fmt = "{}x{}".format(150, 100-10)
frame.master.geometry(fmt)

# print 
# print "winfo_rootx():", frame.master.winfo_rootx()
# print "winfo_rooty():", frame.master.winfo_rooty()

frame.mainloop()

