# file esercizio18.py

import cherrypy

class Esercizio18(object):
	@cherrypy.expose
	def index(self):
		return open("index.html")

	@cherrypy.expose
	def summary(self, nome=None, cognome=None, indirizzo=None, telefono=None, email=None, credit_card=None, verification=None):
		html = "<!DOCTYPE html><html>"
		html += "<body style=\"text-align: center; \">"
		html +=  "<p>Nome: {}</p>".format(nome)
		html +=  "<p>Cognome: {}</p>".format(cognome)
		html +=  "<p>Indirizzo: {}</p>".format(indirizzo)
		html +=  "<p>Telefono: {}</p>".format(telefono)
		html +=  "<p>E-Mail: {}</p>".format(email)
		html +=  "<p>Carta di credito: {}</p>".format(credit_card)
		html += "</body>"
		html += "</html>"

		return html

if __name__ == "__main__":
	cherrypy.quickstart(Esercizio18())

