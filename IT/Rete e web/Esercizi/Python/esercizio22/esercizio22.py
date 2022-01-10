# file esercizio22.py

import cherrypy

class Esercizio22(object):
	@cherrypy.expose
	def index(self):
		counter = cherrypy.session.get("counter", 0) + 1
		cherrypy.session["counter"] = counter

		html = "<!DOCTYPE html><html><body><div>Sei passato a trovarci {} volte!</div></body></html>".format(counter)

		return html

cherrypy.config.update({"tools.sessions.on": True, 
						"tools.sessions.storage_path": ".", 
						"tools.sessions.timeout": 10
						})

if __name__ == "__main__":
	cherrypy.quickstart(Esercizio22())

