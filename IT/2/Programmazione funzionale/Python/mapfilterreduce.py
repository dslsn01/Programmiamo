# file mapfilterreduce.py

from __future__ import print_function, division
from random import randint
from sys import version_info

# la funzione reduce() si trova nel modulo functools a partire da Python3
if version_info[0] > 2: from functools import reduce

v = [randint(1, 100) for n in range(200)]

# converte tutti i voti in centesimi in voti in trentesimi

li = list(map(lambda n : round(n*30/100), v))

# seleziona tutti e soli gli studenti che hanno passato l'esame

app = list(filter(lambda n : n >= 18, li))

print("----- Voti sufficienti -----")
print(sorted(app, reverse=True))
print("-------- RIASSUNTO ---------")
print("{} studenti su {} hanno passato la prova d'esame.".format(len(app), len(li)))

f = lambda n : round(n*30/100)
g = lambda n : n >= 18

bp = list(filter(g, map(f, v))).count(30)

print("{} studenti hanno ottenuto il voto massimo.".format(bp))

# calcola il voto medio di superamento dell'esame

mv = reduce(lambda m, n: m + n, app) / len(app)

print("Voto medio: {}".format(round(mv, 2)))

