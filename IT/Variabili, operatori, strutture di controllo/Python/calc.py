# file calc.py

from __future__ import print_function, division
import re

if hasattr(__builtins__, 'raw_input'): input = raw_input

# legge due numeri da tastiera

o1 = "?"
o2 = o1

# convalida gli operandi

while not re.match("[+-]?[\d]+", o1):
	if not o1: print("Stringa vuota!")
	elif o1 != "?": print("Numero \"{}\" non valido!".format(o1))
	o1 = input("Primo operando: ")

while not re.match("[+-]?[\d]+", o2):
	if not o2: print("Stringa vuota!")
	elif o2 != "?": print("Numero \"{}\" non valido!".format(o2))
	o2 = input("Secondo operando: ")

# converte gli operandi in numeri

n1 = int(o1)
n2 = int(o2)

# legge l'operazione scelta

op = input("Scegli un'operazione:\n+ - somma,\n- - sottrazione,\n* - prodotto,\n/ - divisione\n")

result = 0;

# esegue la somma

if op == "+":
	result = n1 + n2;
	print("{} + {} = {}".format(n1, n2, result))

# esegue la sottrazione

if op == "-":
	result = n1 - n2;
	print("{} - {} = {}".format(n1, n2, result))

# esegue la moltiplicazione

if op == "*":
	result = n1 * n2;
	print("{} * {} = {}".format(n1, n2, result))
		
# esegue la divisione

if op == "/":
	if n2 == 0:
		print("Impossibile eseguire la divisione per zero!")
	else:
		# stampa tre cifre decimali al massimo
		result = n1 / n2;
		print("{} / {} = {:.3f}".format(n1, n2, result))

