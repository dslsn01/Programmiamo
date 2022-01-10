# file esercizio11.py

from __future__ import print_function
import math

def psq(n):
	m = round(math.sqrt(n))
	return True if (m*m) == n else False

ps = list(filter(psq, [n for n in range(1, 100+1)]))

print(ps)

