# file stackVsQueue.py

from __future__ import print_function
from collections import deque

# crea una pila di tre elementi

stack = ["elefante", "giraffa", "tigre"]

print(stack)

# estrae dalla pila l'ultimo elemento aggiunto

e = stack.pop()

print(e)
print(stack)

# crea una coda di tre elementi

queue = deque(["cane", "lupo", "orso"])

print(queue)

# estrae dalla coda il primo elemento aggiunto

e = queue.popleft()

print(e)
print(queue)

