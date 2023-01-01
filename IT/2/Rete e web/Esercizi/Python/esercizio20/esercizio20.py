# file esercizio20.py

import cherrypy

class Esercizio20(object):
	@cherrypy.expose
	def index(self):
		bgcol = cherrypy.request.cookie.get("bgcol", None)

		# se manca il cookie, chiede di selezionare il colore dello sfondo
		if not bgcol:
			return open("index.html")
		else:
			# ...altrimenti visualizza l'homepage del colore selezionato
			return "<!DOCTYPE html><html><body style=\"text-align: center; background-color: {};\"><div style=\"font-weight: bold;\">Benvenuto!</div></body></html>".format(bgcol.value)

	@cherrypy.expose
	def theme(self, bgcol):
		bgCookie = cherrypy.response.cookie
		bgCookie["bgcol"] = bgcol
		bgCookie["bgcol"]["path"] = "/"
		bgCookie["bgcol"]["max-age"] = "3600" # 1 ora

		raise cherrypy.HTTPRedirect("index")

if __name__ == "__main__":
	cherrypy.quickstart(Esercizio20())

