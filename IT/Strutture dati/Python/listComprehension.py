# file listComprehension.py

from __future__ import print_function

# dichiara una lista di stringhe

li = ["tigre", "giraffa", "elefante"]
print(li)

# inizializza la seconda lista con la "list comprehension"

caps = [s.upper() for s in li]
print(caps)

