# file cookies.py

import cherrypy
from datetime import datetime

class Cookies(object):
	@cherrypy.expose
	def index(self):
		loginCookie = cherrypy.request.cookie.get("login", None)

		# se manca il cookie, spedisce un nuovo cookie con la data di connessione
		if not loginCookie:
			login = datetime.now().strftime("%d/%m/%Y %H:%M:%S")

			# imposta un cookie valido per un'ora
			cookies = cherrypy.response.cookie
			cookies["login"] = login
			cookies["login"]["max-age"] = 3600

			return "Ti sei connesso il {}".format(login)

		# se si trova il cookie, visualizza l'ultima connessione memorizzata
		else:
			return "Ultima connessione: " + loginCookie.value

if __name__ == "__main__":
	cherrypy.quickstart(Cookies())

