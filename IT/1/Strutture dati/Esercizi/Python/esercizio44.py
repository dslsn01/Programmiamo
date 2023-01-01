# file esercizio44.py

from __future__ import print_function
from operator import itemgetter

students = {"A23234" : "Mario Rossi", "A01357" : "Luigi Bianchi", "A12579" : "Giovanni Verdi"}
cdl = {"A12579" : "Informatica", "A01357" : "Matematica", "A23234" : "Fisica"}

print("Studenti del corso")

for k, v in sorted(students.items(), key=itemgetter(1)):
	print("Matricola {}, {}, corso di laurea in {}.".format(k, v, cdl[k]))

