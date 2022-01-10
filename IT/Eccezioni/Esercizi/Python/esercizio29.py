# file esercizio29.py

from __future__ import print_function
if hasattr(__builtins__, 'raw_input'): input = raw_input

class ATMAuthException(ValueError):
	pass

class ATMCashWtdrException(ValueError):
	pass

class ATM(object):
	def enterPin(self):
		if not self.__login:
			pin = input("Inserisci il P.I.N.: ")
			if pin == "12345":
				self.__login = True
			else:
				raise ATMAuthException("PIN non valido!")

	def __init__(self):
		self.__login = False
		self.__run = True
		self.__balance = 1500.0

		print("+++++++ Sportello ATM +++++++")

		while self.__run:
			print("\nOperazioni disponibili:\n")
			print("1. Saldo")
			print("2. Prelievo")
			print("3. Deposito")
			print("4. Esci\n")

			oper = input("Scegli l'operazione (1, 2, 3, 4): ")

			try:
				if oper == "1":
					self.enterPin()
					print("\n---------------------")
					print("Saldo corrente: {} euro.".format(self.__balance))
					print("---------------------")

				elif oper == "2":
					self.enterPin()
					s = input("Importo da prelevare: ")
					cash = float(s)
					if self.__balance - cash >= -500:
						self.__balance -= cash
						print("\n---------------------")
						print("Hai prelevato {} euro. Saldo corrente: {}".format(cash, self.__balance))
						print("---------------------")
					else:
						raise ATMCashWtdrException("Conto incapiente!")

				elif oper == "3":
					self.enterPin()
					s = input("Importo da versare: ")
					cash = float(s)
					self.__balance += cash
					print("\n---------------------")
					print("Hai versato {} euro. Saldo corrente: {}".format(cash, self.__balance))
					print("---------------------")

				elif oper == "4":
					print("Grazie di avere utilizzato i nostri servizi ATM.")
					self.__run = False
				else:
					print("Operazione sconosciuta!")

			except ValueError as e:
				print("\nxxxxxxxxxxxxxxxxxxxxx")
				print(e)
				print("xxxxxxxxxxxxxxxxxxxxx")

atm = ATM()

