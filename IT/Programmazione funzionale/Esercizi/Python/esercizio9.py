# file esercizio9.py

from __future__ import print_function

# i numeri pari e multipli di 3 sono tutti e soli i multipli di 6

m = list(map(lambda n : n*6, [n for n in range(1, 100+1)]))

print(m)

