# file esercizio19.py

import cherrypy

class Esercizio19(object):
	@cherrypy.expose
	def index(self):
		return open("index.html")

	@cherrypy.expose
	def summary(self, nome=None, cognome=None, indirizzo=None, telefono=None, email=None, credit_card=None, verification=None):
		if not nome or not cognome:
			raise cherrypy.HTTPError(400, "Nome e/o cognome mancanti!");

		if not indirizzo:
			raise cherrypy.HTTPError(400, "Indirizzo mancante!")

		if not telefono and not email:
			raise cherrypy.HTTPError(400, "Inserire almeno un contatto valido!")

		if not credit_card or not verification:
			raise cherrypy.HTTPError(400, "Numero di carta di credito e/o codice di verifica mancanti o non corretti!")

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
	cherrypy.quickstart(Esercizio19())

