# file esercizio20.py

from __future__ import print_function
if hasattr(__builtins__, 'raw_input'): input = raw_input
import collections
import sqlite3

print("Cerca un film per titolo, anno, regista e attore principale.")

conn = sqlite3.connect("videostore.db")
cursor = conn.cursor()

try:
	query = "SELECT title, year, director, star FROM movies"
	params = collections.OrderedDict()

	title = input("Titolo del film: ")

	if title: params["title"] = title

	year = input("Anno: ")

	if year: params["year"] = year

	director = input("Regista: ")

	if director: params["director"] = director

	star = input("Attore principale: ")

	if star: params["star"] = star

	if len(params) != 0:
		i = 0
		for k in list(params.keys()):
			clause = (" WHERE {} = ?" if i == 0 else " AND {} = ?").format(k)
			query += clause
			i += 1

		cursor.execute(query, tuple(params.values()))
	else:
		cursor.execute(query)

	res = cursor.fetchall()

	if not res:
		print("Film non disponibile in videoteca!")
		exit()

	for film in res:
		s = film[0]
		yr = film[1]
		if yr: s += " ({})".format(yr)
		s += ", regista: {}".format(film[2])
		pr = film[3]
		if pr: s += ", attore principale: {}".format(pr)
		s += "."
		print(s)

except sqlite3.OperationalError as e:
	print(e)

