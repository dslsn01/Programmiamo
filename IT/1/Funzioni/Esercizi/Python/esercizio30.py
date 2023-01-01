# file esercizio30.py

from __future__ import print_function, division
import re

if hasattr(__builtins__, 'raw_input'): input = raw_input

add = lambda n1, n2 : n1 + n2

subtr = lambda n1, n2 : n1 - n2

mult = lambda n1, n2: n1 * n2

divide = lambda n1, n2: n1 / n2 if n2 != 0 else float('nan')

o1 = "?"
o2 = o1

while not re.match("[+-]?[\d]+", o1):
	if not o1: print("Stringa vuota!")
	elif o1 != "?": print("Numero \"{}\" non valido!".format(o1))
	o1 = input("Primo operando: ")

while not re.match("[+-]?[\d]+", o2):
	if not o2: print("Stringa vuota!")
	elif o2 != "?": print("Numero \"{}\" non valido!".format(o2))
	o2 = input("Secondo operando: ")

n1 = int(o1)
n2 = int(o2)

op = input("Scegli un'operazione:\n+ - somma,\n- - sottrazione,\n* - prodotto,\n/ - divisione\n")

result = 0

if op == "+":
	print("{} + {} = {}".format(n1, n2, add(n1, n2)));

if op == "-":
	print("{} - {} = {}".format(n1, n2, subtr(n1, n2)));

if op == "*":
	print("{} * {} = {}".format(n1, n2, mult(n1, n2)))

if op == "/":
	print("{} / {} = {:.3f}".format(n1, n2, divide(n1, n2)))

