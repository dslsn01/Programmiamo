# file esercizio1.py

from __future__ import print_function

li = ["rosso", "verde", "blu"]

i = 0

while (True):
	try:
		print(li[i])
		i += 1
	except IndexError:
		break

print("Fine del programma.")

