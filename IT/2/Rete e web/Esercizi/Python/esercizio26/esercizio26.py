# file esercizio26.py

import cherrypy
from datetime import datetime

class Esercizio26(object):
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
		if not cherrypy.session.get("username", None):
			raise cherrypy.HTTPRedirect("index")

		cherrypy.session.clear()
		return "<!DOCTYPE html><html><body style=\"text-align: center\"><div>Logout effettuato il {}</div></body></html>".format(datetime.now().strftime("%d/%m/%Y %H:%M:%S"))

cherrypy.config.update({ "tools.sessions.on": True })

if __name__ == "__main__":
	cherrypy.quickstart(Esercizio26())

