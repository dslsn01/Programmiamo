# file esercizio22.py

from __future__ import print_function
from sys import version_info

if version_info[0] > 2: from functools import reduce

b = [("De Arte Combinatoria", "Gottfried Wilhelm Leibniz", 1666), ("Discorso sulla Metafisica", "Gottfried Wilhelm Leibniz", 1686), ("Sulla strada", "Jack Kerouac", 1957), ("Il Libro dei Sogni", "Jack Kerouac", 1960), ("Sessanta racconti", "Dino Buzzati", 1958), ("Il deserto dei Tartari", "Dino Buzzati", 1940), ("Un amore", "Dino Buzzati", 1963), ("Zanna bianca", "Jack London", 1906)]

li = list(sorted(filter(lambda t : t[1] == "Dino Buzzati", b), key=lambda t: t[2], reverse=True))

print(reduce(lambda s1, s2: "{}\n{}".format(s1, s2), map(lambda t: "\"{}\", {} ({})".format(t[0], t[1], t[2]), li)))

