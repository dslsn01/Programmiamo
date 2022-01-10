# file player.py

class Player(object):
	def __init__(self, name):
		self.name = name
		self.score = 100

	def addScore(self, incr):
		self.__score += incr

	def getName(self):
		return self.__name

	def setName(self, name):
		self.__name = name
	
	def getScore(self):
		return self.__score

	def setScore(self, score):
		self.__score = score

	name = property(getName, setName)
	score = property(getScore, setScore)

