# file esercizio28.py
# -*- coding: utf-8 -*-

from __future__ import print_function, unicode_literals
from sys import stdin, stdout, version_info
import re
if hasattr(__builtins__, 'raw_input'): input = raw_input

s = input("Scrivi una parola (o una frase): ")
if version_info[0] < 3: s = s.decode(stdin.encoding)

if not s:
	print("Stringa vuota!")
	exit()

stdout.write("Controllando i caratteri: ")

voc = ('a', 'à', 'e', 'è', 'i', 'ì', 'o', 'ò', '', 'ù')

# salta punteggiatura, spazi, simboli speciali...

li = [c for c in s if c.isalpha()]
cons = 0

for c in li:
	if not c.lower() in voc:
		cons += 1

print("   -> la stringa \"{}\" contiene {} consonanti.".format(s, cons))

stdout.write("Con le espressioni regolari: ")

cons = 0

# elimina punteggiatura, spazi, simboli speciali...

s2 = re.sub("[^a-zA-ZÀ-ù]", "", s)

if s2:
	# esclude tutto ciò che non è una vocale
	for match in re.findall("[^aeiouÀ-ù]", s2, flags=re.IGNORECASE):
		cons += 1

print("-> la stringa \"{}\" contiene {} consonanti.".format(s, cons))

