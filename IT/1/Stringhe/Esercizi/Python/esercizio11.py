# file esercizio11.py

from __future__ import print_function, unicode_literals
from sys import stdin, version_info
if hasattr(__builtins__, 'raw_input'): input = raw_input

s = input("Scrivi una parola (o una frase): ")
# solo su Python 2 serve decodificare
if version_info[0] < 3: s = s.decode(stdin.encoding)

# controlla che la stringa non sia vuota

if not s:
	print("Stringa vuota!")
	exit()

l = len(s)
ch = 0
num = 0
sp = 0

# analizza i caratteri uno per uno

for c in s:
	if c.isalpha(): ch += 1
	elif c.isdigit(): num += 1
	else: sp += 1

print("La stringa \"{}\" ({} caratteri totali) contiene {} lettere, {} numeri e {} simboli.".format(s, l, ch, num, sp))

