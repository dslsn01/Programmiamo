# file esercizio25.py

import cherrypy

class Esercizio25(object):
	@cherrypy.expose
	def index(self):
		username = cherrypy.session.get("username", None)
		return open("index.html") if not username else "<!DOCTYPE html><html><body style=\"text-align: center\"><div style=\"font-weight: bold;\">Benvenuto, {}!</div></body></html>".format(username)

	@cherrypy.expose
	def welcome(self, name):
		username = "ignoto" if not name else name
		cherrypy.session["username"] = username

		raise cherrypy.HTTPRedirect("index")

cherrypy.config.update({ "tools.sessions.on": True })

if __name__ == "__main__":
	cherrypy.quickstart(Esercizio25())

