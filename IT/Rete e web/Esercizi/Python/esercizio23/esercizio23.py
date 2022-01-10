# file esercizio23.py

import cherrypy

class Esercizio23(object):
	@cherrypy.expose
	def index(self):
		username = cherrypy.request.cookie.get("username", None)
		return open("index.html") if not username else "<!DOCTYPE html><html><body style=\"text-align: center\"><div style=\"font-weight: bold;\">Benvenuto, {}!</div></body></html>".format(username.value)

	@cherrypy.expose
	def welcome(self, name):
		username = "ignoto" if not name else name
		cookie = cherrypy.response.cookie
		cookie["username"] = username
		cookie["username"]["max-age"] = 3600 # cookie valido per un'ora

		raise cherrypy.HTTPRedirect("index")

if __name__ == "__main__":
	cherrypy.quickstart(Esercizio23())

