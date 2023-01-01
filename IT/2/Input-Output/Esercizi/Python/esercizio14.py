# file esercizio14.py

try:
	with open("file.txt", "r") as doc:
		linecount = sum(1 for l in doc)

	print("Il file \"{}\" contiene {} righe.".format(doc.name, linecount))

except IOError as e:
	print(e)

