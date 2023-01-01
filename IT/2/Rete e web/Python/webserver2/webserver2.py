# file webserver2.py

import cherrypy

class Webserver(object):
	@cherrypy.expose
	def index(self):
		html = "<!DOCTYPE html><html><head><title>La mia pagina web</title></head><body><p>Ciao, mondo!</p></body></html>"

		return html

if __name__ == "__main__":
	cherrypy.quickstart(Webserver())

