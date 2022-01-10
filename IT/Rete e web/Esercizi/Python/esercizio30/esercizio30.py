# file esercizio30.py

import cherrypy

class Esercizio30(object):
	@cherrypy.expose
	def index(self):
		return open("index.html")

	@cherrypy.expose
	def beratio(self, loan, debts, income, nMonths):
		if loan and income:
			try:
				_loan = float(loan)
				_debts = float(debts) if debts else 0
				_nMonths = int(nMonths)
				_income = float(income)

				html = "<!DOCTYPE html><html><body style=\"text-align: center\"><div style=\"font-style: italic;\">Riassunto</div><br/>"
				html += "<div>Prestito richiesto: {} euro</div>".format(loan) 
				html += "<div>Reddito mensile: {} euro</div>".format(income)
				html += "<div>Totale debiti pregressi: {} euro mensili</div>".format(debts)
				html += "<div>Numero rate desiderato: {}</div><br/>".format(nMonths)

				if _loan < 500 or _loan > 30000:
					raise cherrypy.HTTPError(400, "L'importo del prestito richiesto dev'essere compreso tra 500 e 30000 euro!")

				# tasso d'interesse annuo del 6,5%
				taeg = (_loan / 100) * 6.5

				# calcola la rata mensile (incluso il TAEG): 
				payment = ((_loan + taeg) / _nMonths)

				html += "<div style=\"font-weight: bold\">Importo rata mensile: {0:.2f}</div>".format(payment)
				html += "<div>(Alla rata si applica un tasso di interesse annuo globale del 6.5% annuo.)</div><br/>"

				beratio = ((payment + _debts) / _income) * 100

				if beratio <= 36:
					html += "<div style=\"color:green;\">Rapporto debiti / reddito uguale a {0:.2f}%. Possiamo concedere il prestito.</div>".format(beratio)
				else:
					html += "<div style=\"color:red;\">Rapporto debiti / reddito eccessivo ({0:.2f}%). Impossibile concedere il prestito.</div>".format(beratio)

				html += "</body></html>"

				return html
			except ValueError as e:
				raise cherrypy.HTTPError(400, "Inserito un importo scorretto!")
		else:
			raise cherrypy.HTTPError(400, "Prestito e stipendio non possono essere nulli!")

if __name__ == "__main__":
	cherrypy.quickstart(Esercizio30())

