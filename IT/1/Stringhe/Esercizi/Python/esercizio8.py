# file esercizio8.py

from __future__ import print_function

n = ("United States of America", "Unione delle Repubbliche Socialiste Sovietiche", "European Union")

for s in n:
	acr = ""
	tokens = s.split()
	for t in tokens:
		i = t[0]
		if i.isupper():
			acr += i + "."

	print("{} ({})".format(acr, s))

