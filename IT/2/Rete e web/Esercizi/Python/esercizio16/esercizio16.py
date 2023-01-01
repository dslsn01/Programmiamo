# file esercizio16

import cherrypy

class Esercizio16(object):
	@cherrypy.expose
	def index(self):
		return open("index.html")

	@cherrypy.expose
	def welcome(self, name):
		n = "ignoto" if not name else name
		return "<!DOCTYPE html><html><body style=\"text-align: center\"><div style=\"font-weight: bold;\">Benvenuto, {}!</div></body></html>".format(n)

if __name__ == "__main__":
	cherrypy.quickstart(Esercizio16())

