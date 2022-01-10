# file esercizio19.py

from __future__ import print_function, unicode_literals
import re

# formato SI
si = "1 234 567.89"

# formato USA
us = si.replace(" ", ",")

# formato italiano
it = si.replace(".", ",").replace(" ", ".")

print("Stile SI: {}".format(si))
print("Stile US: {}".format(us))
print("Stile IT: {}".format(it))

