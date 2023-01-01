# file esercizio29.py

import cherrypy

class Esercizio29(object):
	def __init__(self):
		# listino prezzi
		self.__prices = {}

		# prezzi degli smartphone
		self.__prices["Samsung Galaxy"] = 500
		self.__prices["Apple iPhone"] = 800
		self.__prices["Huawei P"] = 200
		self.__prices["Sony Xperia"] = 250

		# prezzi dei computer portatili
		self.__prices["HP Pavilion"] = 1300
		self.__prices["Lenovo Thinkpad"] = 1200
		self.__prices["Fujitsu Lifebook"] = 1100

		# prezzi dei televisori
		self.__prices["Philips 22p"] = 150
		self.__prices["Philips 32p"] = 220
		self.__prices["Sony 32p"] = 380
		self.__prices["Samsung 49p"] = 600
		self.__prices["Sony 55p"] = 1200

	@cherrypy.expose
	def index(self):
		return open("index.html")

	@cherrypy.expose
	def summary(self, smartphone=None, notebook=None, tv=None):
		html = "<!DOCTYPE html><html><body style=\"text-align: center\">"
		html += "<h2>Riassunto acquisti (IVA inclusa):</h2>"
		total = 0

		if smartphone:
			price = self.__prices[smartphone]
			total += price
			html += "<div>{} = {} euro</div>".format(smartphone, price)

		if notebook:
			price = self.__prices[notebook]
			total += price
			html += "<div>{} = {} euro</div>".format(notebook, price)

		if tv:
			price = self.__prices[tv]
			total += price
			html += "<div>{} = {} euro</div>".format(tv, price)

		if total != 0:
			html += "<br/><div style=\"font-weight: bold\">Totale spesa: {} euro.</div>".format(total)
		else:
			html = "<div style=\"font-weight: bold\">Non hai effettuato nessun acquisto.</div>"

		html += "</body></html>"

		return html

if __name__ == "__main__":
	cherrypy.quickstart(Esercizio29())

