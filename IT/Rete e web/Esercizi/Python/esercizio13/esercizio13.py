# file esercizio13.py

import cherrypy
from datetime import datetime

class Esercizio13(object):
	@cherrypy.expose
	def index(self):
		fmt = datetime.now().strftime("%d/%m/%Y ore %H:%M:%S")
		return "Ti sei connesso il {}.".format(fmt)

if __name__ == "__main__":
	cherrypy.quickstart(Esercizio13())

