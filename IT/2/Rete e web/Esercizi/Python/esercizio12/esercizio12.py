# file esercizio12.py

import cherrypy

class Esercizio12(object):
	@cherrypy.expose
	def index(self):
		return open("index.html")

	@cherrypy.expose
	def details(self):
		return open("contatti.html")

if __name__ == "__main__":
	cherrypy.quickstart(Esercizio12())

