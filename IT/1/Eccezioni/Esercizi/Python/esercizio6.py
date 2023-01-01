# file esercizio6.py

from __future__ import print_function

class Foo(object):
	def baz(self):
		print("Foo")

class Bar(object):
	def baz(self):
		raise NotImplementedError("Operazione non supportata!")

objs = [Foo(), Bar(), Foo()]

for obj in objs:
	try:
		obj.baz()
	except NotImplementedError as e:
		print(e)

print("Fine del programma.")

