# file part.py

from __future__ import print_function, division
from functools import partial

# funzione che calcola la percentuale, ad es. il 60% di 120

percent = lambda x, y : x / 100 * y

# calcola il 60% di 120: invoca la funzione con entrambi i parametri

print("60% di 120 = {}".format(percent(120, 60)))

# applicazione parziale della funzione: fissa il primo parametro al variare del secondo
part = partial(percent, 70)

print("30% di 70 = {:.1f}".format(part(30)))
print("60% di 70 = {:.1f}".format(part(60)))
print("90% di 70 = {:.1f}".format(part(90)))

