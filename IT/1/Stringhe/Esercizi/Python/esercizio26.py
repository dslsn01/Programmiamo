# file esercizio26.py
# -*- coding: utf-8 -*-

from __future__ import print_function, unicode_literals
from sys import stdin
from os import linesep
import re

s = "Nel mezzo del cammin di nostra vita" + linesep
s += "mi ritrovai per una selva oscura" + linesep
s += "chè la retta via era smarrita."

print("\"{}\"".format(s))

# contatore delle righe
rCount = 0

for r in re.findall(r"([^\r\n]+)", s): rCount += 1

# contatore delle parole
wCount = 0

for w in re.findall(r"([a-zA-ZÀ-ù']+)", s): wCount += 1

# contatore delle frasi
sCount = 0

for p in re.findall(r"(.*[\.\r\n])", s): sCount += 1

print("Il testo contiene {} righe, {} frasi, {} parole, {} caratteri.".format(rCount, sCount, wCount, len(s)))

