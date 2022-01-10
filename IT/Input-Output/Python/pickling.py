# file pickling.py

from __future__ import print_function

from player import Player
import pickle

player = Player("Jimmy");

# incrementa il punteggio del giocatore

player.addScore(150);

print("Punteggio di {} prima della serializzazione: {}".format(player.name, player.score))

output = open("player.pkl", "wb")
pickle.dump(player, output, pickle.HIGHEST_PROTOCOL)
output.close()

print("Giocatore salvato su disco.")

