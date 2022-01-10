# file esercizio21.py

import cherrypy

class Esercizio21(object):
	@cherrypy.expose
	def index(self):
		langCookie = cherrypy.request.cookie.get("lang", None)

		# se manca il cookie, chiede di selezionare la lingua del sito
		if not langCookie:
			return open("index.html")
		else:
			# ...altrimenti visualizza un messaggio di benvenuto nella lingua scelta

			msg = "Benvenuto!" if langCookie.value == "it" else "Welcome!"
			return "<!DOCTYPE html><html><body style=\"text-align: center;\"><div style=\"font-weight: bold;\">{}</div></bodt></html>".format(msg)

	@cherrypy.expose
	def lang(self, lang):
		langCookie = cherrypy.response.cookie
		langCookie["lang"] = lang
		langCookie["lang"]["path"] = "/"
		langCookie["lang"]["max-age"] = "3600" # 1 ora

		raise cherrypy.HTTPRedirect("index")

if __name__ == "__main__":
	cherrypy.quickstart(Esercizio21())

