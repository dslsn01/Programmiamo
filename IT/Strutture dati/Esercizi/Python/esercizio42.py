# file esercizio42.py

from __future__ import print_function

colors = {1 : "rosso", 2 : "verde", 3 : "blu", 4 : "giallo", 5 : "ciano", 6 : "magenta", 7 : "arancio", 8 : "viola", 9 : "bianco", 10 : "nero"}

print("Colori = {}".format(colors))

k = 1
rgb = {key : colors[key] for key in range(1, 4)}
cmy = {key : colors[key] for key in range(4, 7)}
tc = {key : colors[key] for key in range(7, 9)}
nc = {key : colors[key] for key in range(9, 11)}

print("Colori primari = {}".format(rgb))
print("Colori secondari = {}".format(cmy))
print("Colori terziari = {}".format(tc))
print("Colori neutri = {}".format(nc))

