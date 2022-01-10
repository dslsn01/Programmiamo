# file esercizio20.py

from __future__ import print_function

# funzione "successore"

s = lambda n : n + 1

# restituisce il successore del successore di un numero

ff = lambda f, n : f(f(n))

# stampa "2"

print("Successore del successore di zero: {}".format(ff(s, 0)))

