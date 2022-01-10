# file esercizio11.py

import cherrypy

class Esercizio11(object):
	@cherrypy.expose
	def index(self):
		return open("index.html")

if __name__ == "__main__":
	cherrypy.quickstart(Esercizio11())

