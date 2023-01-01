# file esercizio18.py
# -*- coding: utf-8 -*-

from __future__ import print_function, unicode_literals
from os import linesep

s = "David Bowman: 'Hal, apri la saracinesca esterna! Pronto Hal, mi ricevi? Pronto Hal, mi ricevi?'" + linesep
s += "HAL 9000: 'Affermativo, David. Ti ricevo'." + linesep
s += "David Bowman: 'Apri la saracinesca esterna, Hal'." + linesep
s += "HAL 9000: 'Mi dispiace David, purtroppo non posso farlo'." + linesep
s += "David Bowman: 'Qual è il motivo?'" + linesep
s += "HAL 9000: 'Credo che tu lo sappia altrettanto bene quanto me'."

print(s)

print(linesep + "-> Sostituiamo i singoli apici con i doppi apici." + linesep)

s = s.replace("'", "\"")

print(s)

