# file string_search.py

from __future__ import print_function, unicode_literals

s = "Cantami, o Diva, del pelide Achille l'ira funesta"

indexA = s.find("A")
print("Indice di 'A': {}".format(indexA))

indexZ = s.find("Z")
print("Indice di 'Z': {}".format(indexZ))

indexAchille = s.find("Achille")
print("Indice della parola 'Achille': {}".format(indexAchille))

