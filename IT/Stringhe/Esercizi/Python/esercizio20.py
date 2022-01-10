# file esercizio20.py

from __future__ import print_function, unicode_literals
import re

# formato SI
si = "1 234 567.89"

# formato USA
r = r"[\s]"
us = re.sub(r, ",", si)

# formato italiano
it = re.sub(r"[\s\.]", lambda m : "." if m.group(0) == " " else ",", si)

print("Stile SI: {}".format(si))
print("Stile US: {}".format(us))
print("Stile IT: {}".format(it))

