# file sessions.py

import cherrypy
from datetime import datetime

class Sessions(object):
	@cherrypy.expose
	def index(self):
		session = cherrypy.session
		login = session.get("login", None)

		# se la sessione non si trova, crea una nuova sessione dove memorizza l'ora corrente
		if not login:
			login = datetime.now()
			cherrypy.session["login"] = login

			return "Ti sei connesso il {}".format(login.strftime("%d/%m/%Y %H:%M:%S"))

		# se presente, visualizza l'ora dell'ultima connessione in sessione
		else:
			return "Ultima connessione: {}".format(login.strftime("%d/%m/%Y %H:%M:%S"))

cherrypy.config.update({ "tools.sessions.on": True })

if __name__ == "__main__":
	cherrypy.quickstart(Sessions())

