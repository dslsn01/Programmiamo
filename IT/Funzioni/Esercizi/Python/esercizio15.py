# file esercizio15.py

from __future__ import print_function

def exp(b, ex):
	return b**ex

print("Calcolo delle potenze.")

b = 1
ex = 2

while (ex <= 10):
	print("Potenza di {} elevato a {} = {}".format(b, ex, exp(b, ex)))
	b += 1
	ex += 1

