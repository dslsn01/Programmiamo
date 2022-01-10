# file esercizio24.py

import cherrypy
from datetime import datetime

class Esercizio24(object):
	@cherrypy.expose
	def index(self):
		username = cherrypy.request.cookie.get("username", None)

		if not username:
			return open("index.html")
		else:
			html = "<!DOCTYPE html><html>"
			html +=  "<body style=\"text-align: center\">"
			html +=   "<div style=\"font-weight: bold;\">Benvenuto, {}!</div>".format(username.value)
			html +=   "<a href='logout'>Esci</a>"
			html +=  "</body>"
			html += "</html>"

			return html

	@cherrypy.expose
	def welcome(self, name):
		username = "ignoto" if not name else name
		cookie = cherrypy.response.cookie
		cookie["username"] = username
		cookie["username"]["max-age"] = 3600 # cookie valido per un'ora

		raise cherrypy.HTTPRedirect("index")

	@cherrypy.expose
	def logout(self):
		if not cherrypy.request.cookie.get("username", None):
			raise cherrypy.HTTPRedirect("index")

		cookie = cherrypy.response.cookie
		cookie["username"]["max-age"] = 0

		return "<!DOCTYPE html><html><body style=\"text-align: center\"><div>Logout effettuato il {}</div></body></html>".format(datetime.now().strftime("%d/%m/%Y %H:%M:%S"))

if __name__ == "__main__":
	cherrypy.quickstart(Esercizio24())

