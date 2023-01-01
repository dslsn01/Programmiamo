# file esercizio15.py

import cherrypy

class Esercizio15(object):
	@cherrypy.expose
	def index(self):
		raise cherrypy.HTTPRedirect("redirect", status=301)

	@cherrypy.expose
	def redirect(self):
		return open("redirect.html")

if __name__ == "__main__":
	cherrypy.quickstart(Esercizio15())

