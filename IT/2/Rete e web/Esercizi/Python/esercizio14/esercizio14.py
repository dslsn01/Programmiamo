# file esercizio14.py

import cherrypy

class Esercizio14(object):
	@cherrypy.expose
	def index(self):
		raise cherrypy.HTTPRedirect("redirect")

	@cherrypy.expose
	def redirect(self):
		return open("redirect.html")

if __name__ == "__main__":
	cherrypy.quickstart(Esercizio14())

