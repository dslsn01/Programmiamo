# file test_regex.py

from __future__ import print_function, unicode_literals
import re

# prepara un'espressione regolare, e la compila per essere riutilizzata

regex = r"^Ul[iy](?:ss|x)es?$"
pattern = re.compile(regex, re.IGNORECASE)

s = ["Ulisse", "ulysse", "Ulysses", "ULIXES"]

for name in s:
	if pattern.match(name): 
		print("La regex \"{}\" coincide con il nome \"{}\".".format(regex, name))

