# file webserver1.py

import cherrypy

class Webserver(object):
	@cherrypy.expose
	def index(self):
		return open("index.html")

if __name__ == "__main__":
	cherrypy.quickstart(Webserver())

