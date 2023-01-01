# file pickling2.py

from __future__ import print_function
import pickle

class Sword(object):
	def __init__(self, name):
		self.name = name

# la classe Highlander contiene quale membro un oggetto del tipo Sword

class Highlander(object):
	def __init__(self, sword):
		self.sword = sword

highlander = Highlander(Sword("Excalibur"));

print("Spada prima della serializzazione: {}".format(highlander.sword.name))

output = open("highlander.pkl", "wb")
pickle.dump(highlander, output, pickle.HIGHEST_PROTOCOL)
output.close()

pkl = open("highlander.pkl", "rb")
restored = pickle.load(pkl)

sword = restored.sword
print("Spada dopo la serializzazione: {}".format(sword.name))

pkl.close()

