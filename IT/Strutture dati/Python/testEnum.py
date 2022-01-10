# file testEnum.py

from __future__ import print_function
from enum import Enum
from random import randint

class Color(Enum):
	RED = 0
	YELLOW = 1
	GREEN = 2

# inizializza casualmente il colore del semaforo

currentColor = Color(randint(0, 2))

# confronta il colore del semaforo con tutti i colori possibili

if currentColor is Color.RED:
	print("Semaforo ROSSO: fermati!")
elif currentColor is Color.YELLOW:
	print("Semaforo GIALLO o lampeggiante: prudenza.")
elif currentColor is Color.GREEN:
	print("Semaforo VERDE: passa senza problemi...")
else:
	print("Semaforo guasto?")

