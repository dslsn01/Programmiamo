# file esercizio27.py
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
v = 0

for c in s:
	if c.lower() in voc: v += 1

print("   -> la stringa \"{}\" contiene {} vocali.".format(s, v))

stdout.write("Con le espressioni regolari: ")

r = "[aeiouÀ-ù]"
v = 0

for match in re.findall(r, s, flags=re.IGNORECASE):
	v += 1

print("-> la stringa \"{}\" contiene {} vocali.".format(s, v))

