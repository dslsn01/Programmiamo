# file esercizio45.py

from __future__ import print_function
if hasattr(__builtins__, 'raw_input'): input = raw_input
from operator import itemgetter

students = {"A23234" : "Mario Rossi", "A01357" : "Luigi Bianchi", "A12579" : "Giovanni Verdi"}
grades = {}

print("Risultati prova d'esame")

for student in students.items():
	s = input("Lo studente " + student[1] + " ha passato l'esame? s/n: ")
 
	if s.lower() == "s":
		matr = student[0]
		grade = input("Voto: ")
		if not grade or not grade.isdigit() or int(grade) < 18:
			print("Voto non valido!")
			continue

		grades[matr] = int(grade)

for k, v in grades.items():
	print("Lo studente {} ha superato l'esame finale con il voto {}.".format(students[k], v))

if len(grades) == len(students):
	print("Tutti gli studenti hanno passato la prova d'esame.")
	students.clear()
else:
	commons = set(students.keys()) & set(grades.keys())

	students = {i : students[i] for i in students if i not in commons}

	for k, v in students.items():
		print("Lo studente {} deve ancora sostenere la prova d'esame.".format(v))

