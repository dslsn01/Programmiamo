# file webapp.py

import cherrypy

class Webapp(object):
	@cherrypy.expose
	def index(self):
		return open("index.html")

	@cherrypy.expose
	def home(self, username, password):
		if username == password:
			return "<!DOCTYPE html><html><body><p style=\"font-weight: bold;\">Benvenuto, {}!</p></body></html>".format(username)
		else:
			raise cherrypy.HTTPError(401, "Username / password non corretti!")

if __name__ == "__main__":
	cherrypy.quickstart(Webapp())

