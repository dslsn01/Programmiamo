# file esercizio27.py

import cherrypy

class Esercizio27(object):
	@cherrypy.expose
	def index(self):
		username = cherrypy.session.get("username", None)

		if not username:
			return open("index.html")
		else:
			html = "<!DOCTYPE html><html>"
			html +=  "<body style=\"text-align: center\">"
			html +=   "<div style=\"font-weight: bold;\">Benvenuto, {}!</div>".format(username)
			html +=   "<a href='logout'>Esci</a>"
			html +=  "</body>"
			html += "</html>"

			return html

	@cherrypy.expose
	def welcome(self, name):
		username = "ignoto" if not name else name
		cherrypy.session["username"] = username

		raise cherrypy.HTTPRedirect("index")

	@cherrypy.expose
	def logout(self):
		cherrypy.session.clear()
		raise cherrypy.HTTPRedirect("index")

cherrypy.config.update({ "tools.sessions.on": True })

if __name__ == "__main__":
	cherrypy.quickstart(Esercizio27())

