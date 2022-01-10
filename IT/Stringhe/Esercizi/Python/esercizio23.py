# file esercizio23.py

from __future__ import print_function, unicode_literals
import re

s = "qui. quo. qua."

print(s)

s = re.sub(r"(^[\w]|\.\s[\w])", lambda m : m.group(1).upper(), s)

print(s)

