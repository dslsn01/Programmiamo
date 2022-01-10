# file esercizio21.py

from __future__ import print_function, unicode_literals
import re

s = "Il rosso e il nero"

r = r"Il ([a-zA-Z]+) e il ([a-zA-Z]+)"
s2 = re.sub(r, r"Il \2 e il \1", s)

print(s)
print(s2)

