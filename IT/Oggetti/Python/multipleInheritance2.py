# file multipleInheritance2.py

from __future__ import print_function

class Foo:
	def f(self):
		print("Foo::baz")

class Bar:
	def f(self):
		print("Bar::baz()")

class Baz(Foo, Bar):
	pass

p = Baz()

# quale versione del metodo f() viene ereditata dalla sottoclasse Baz?

p.f()

