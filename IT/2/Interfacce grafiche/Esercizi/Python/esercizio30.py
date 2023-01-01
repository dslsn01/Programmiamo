# file esercizio30.py

from __future__ import unicode_literals, division

try:
	from tkinter import Frame, Text, Button, END
except ImportError:
	from Tkinter import Frame, Text, Button, END

import re
import math

class MyPanel(Frame):
	def __init__(self, parent): 
		self.buttons = ["7", "8", "9", u"\u00F7", "CE", "C", "4", "5", "6", u"\u2217", "(", ")", "1", "2", "3", "-", u"x\u00b2", u"\u221A", "0", ".", "%", "+", "="]
		Frame.__init__(self, master=parent, width=300, height=300)

		r = 1
		c = 0
		for s in self.buttons:
			b = Button(self, text=s)
			b.bind("<Button-1>", self.clickHandler)
			if s != "=":
				b.grid(row=r, column=c, sticky="ew")
				c += 1
			else:
				b.grid(row=r, column=c, columnspan=2, sticky="ew")
				c += 2
			if c % 6 == 0:
				c = 0
				r += 1

		self.pack()

	def clickHandler(self, event):
		s = event.widget["text"]
		if s == "=":
			try:
				expr = self.master.s.get(1.0, END).rstrip()
				rpn = self.master.infixToRpn(expr)
				result = self.master.evaluate(rpn)
				self.master.s.delete(1.0, END)
				self.master.s.insert(1.0, result)
				self.master.s.tag_add("right", 1.0, END)
			except Exception:
				# gestione espressioni malformate
				self.master.s.delete(1.0, END)
				self.master.s.insert(1.0, "Espressione malformata")
				self.master.s.tag_add("right", 1.0, END)
		elif s == "C":
			self.master.s.delete(1.0, END)
		elif s == "CE":
			onsc = self.master.s.get(1.0, END).rstrip()
			n = []
			for m in re.finditer(r"[\d]+(\.[\d]+)?", onsc):
				n.append(m.group())
			last = n[-1]
			i = onsc.rfind(last)
			self.master.s.delete(1.0, END)
			self.master.s.insert(1.0, onsc[:i])
			self.master.s.tag_add("right", 1.0, END)
		else:
			if self.master.s.get(1.0, END).rstrip() == "Espressione malformata":
				self.master.s.delete(1.0, END)

			# elevamento al quadrato
			elif s == "x\u00b2": s = "\u00b2"
			self.master.s.insert(END, s)
			self.master.s.tag_add("right", 1.0, END)

class Esercizio30(Frame):
	def __init__(self):
		Frame.__init__(self, width=300, height=300)

		self.ops = {"+" : [0, 0], "-" : [0, 0], "*" : [1, 0], "/" : [1, 0], "^" : [2, 1]}
		self.s = Text(self, width=30, height=5)
		self.s.tag_configure("right", justify="right")
		self.s.pack()
		self.p = MyPanel(self)
		self.pack()
		self.master.wm_title("Calcolatrice")
		self.mainloop()

	def infixToRpn(self, expr):
		expr = expr.replace("\u00b2", "^2").replace("\u221A", "sqrt").replace("\u00F7", "/").replace("\u2217", "*")
		reg = r"^[-+]?[\d]+(\.[\d]+)?%?|[\d]+(\.[\d]+)?%?|sqrt[\d]+(\.[\d]+)?|[()*/+-\^]"
		tokens = []
		for m in re.finditer(reg, expr):
			tokens.append(m.group())

		rpn = []
		stackOps = []

		for token in tokens:
			if token in self.ops.keys():
				prop = self.ops[token]
				prec = prop[0]
				ass = prop[1]

				while stackOps and stackOps[-1] in self.ops.keys():
					opPrec = self.ops[stackOps[-1]][0]
					if prec < opPrec or prec == opPrec and ass == 0:
						rpn.append(stackOps.pop())
					break
				stackOps.append(token)
			elif token == "(":
				stackOps.append(token)
			elif token == ")":
				while stackOps and stackOps[-1] != "(":
					rpn.append(stackOps.pop())
				stackOps.pop()
			else: # numero o funzione
				# se si tratta di una funzione, la valuta e salva subito il risultato
				if token.find("sqrt") == 0:
					for m in re.finditer(r"[\d]+(\.[\d]+)?", token):
						f = m.group()
					if f:
						d = float(f)
						res = math.sqrt(d)
						token = str(res)
				rpn.append(token)

		while stackOps:
			rpn.append(stackOps.pop())

		return rpn

	def evaluate(self, rpn):
		stack = []
		for token in rpn:
			if token not in self.ops.keys():
				stack.append(token)
			else:
				s = stack.pop()
				o2 = 0.0
				o1 = float(stack.pop())

				if not s[-1] == "%": o2 = float(s)
				else:
					# calcola la percentuale
					s = s.replace("%", "")
					o2 = o1/100*float(s)

				result = 0.0
				if token == "+": result = o1 + o2
				elif token == "-": result = o1 - o2
				elif token == "*": result = o1 * o2
				elif token == "/": result = o1 / o2
				elif token == "^": result = o1**o2

				stack.append(result)

		return float(stack.pop())

calc = Esercizio30()

