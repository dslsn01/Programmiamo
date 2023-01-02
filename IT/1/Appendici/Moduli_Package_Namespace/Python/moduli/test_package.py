# modulo test_package.py

from __future__ import print_function

import mypackage.utils
# from mypackage.utils import Foo

class Foo:
	def bar(self):
		print("bar baz")

foo1 = Foo()
foo1.bar()

foo2 = mypackage.utils.Foo()
foo2.bar()

