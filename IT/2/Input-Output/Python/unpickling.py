# file unpickling.py

from __future__ import print_function
import pickle

# legge l'oggetto serializzato nel file e ripristina l'oggetto originale

pkl = open("player.pkl", "rb")

player = pickle.load(pkl)

print("Giocatore ripristinato con successo. \nPunteggio di {} dopo il ripristino: {}".format(player.name, player.score))

pkl.close()

