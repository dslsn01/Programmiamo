# file test_unicode.py

from __future__ import print_function, unicode_literals
from sys import stdin, stdout, version_info
from os import linesep

# versione di Python attualmente in uso
pythonVersion = version_info[0]

print("\tCaratteri ASCII stampabili (32-127): " + linesep)

for i in range(32, 127):
	stdout.write(chr(i) + " ")

stdout.write(linesep)

print(linesep + "\tCaratteri Unicode stampabili (160-255): " + linesep)

# se si usa Python 2, associamo l'alias chr() alla funzione unichr()
if hasattr(__builtins__, 'unichr'): chr = unichr

for i in range(160, 256):
	stdout.write(chr(i) + " ")

stdout.write(linesep)

stdout.write(linesep + "Scrivi _una sola parola_ (no numeri, spazi o punteggiatura: ammessi caratteri accentati): ")

# se si usa Python 2, raw_input() restituisce una stringa "non unicode"
if pythonVersion < 3:
	s = raw_input()
	print("Stringa inserita di tipo {}, contiene {} caratteri.".format(type(s), len(s)))
	if not s.isalpha(): print("Parola non valida!")

	# necessaria la decodifica manuale

	s = s.decode(stdin.encoding)

	if s.isalpha():
		print("La stringa convertita in {} contiene {} caratteri.".format(type(s), len(s)))

else: # se si usa python 3, le stringhe sono unicode per default, senza bisogno di conversione
	s = input()

	if s.isalpha():
		print("Stringa inserita di tipo: {}, contiene {} caratteri.".format(type(s), len(s)))

	# possiamo riconvertire una stringa unicode in sequenza di byte

	b = s.encode(stdin.encoding)
	print("La stringa convertita in {} contiene {} caratteri.".format(type(b), len(b)))

