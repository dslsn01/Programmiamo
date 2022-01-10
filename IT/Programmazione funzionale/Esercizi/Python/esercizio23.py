# file esercizio23.py

from __future__ import print_function
from datetime import date, datetime
# se non presente, installare il modulo 'dateutil' con
# pip install python-dateutil
from dateutil.relativedelta import relativedelta
from sys import version_info

if version_info[0] > 2: from functools import reduce

def f(t):
	bd = datetime.strptime(t[2], "%d/%m/%Y")
	p = relativedelta(date.today(), bd)
	y = p.years
	m = p.months
	return "{} {}, {}".format(t[0], t[1], "({} anni)".format(y) if not m else "({} anni, {} mesi)".format(y, m))

b = [("John", "Doe", "01/09/1995"), ("Jane", "Doe", "31/12/2000"), ("Joe", "Bloggs", "01/05/2010"), ("Mario", "Rossi", "01/09/1980"), ("Luigi", "Bianchi", "01/01/1970"), ("Giovanni", "Verdi", "01/11/1985")]

# data di 18 anni fa

d = datetime.now() - relativedelta(years=18);

s = reduce(lambda s1, s2: "{}\n{}".format(s1, s2), map(f, sorted(filter(lambda t : relativedelta(d, datetime.strptime(t[2], "%d/%m/%Y")).years >= 0, b), key=lambda t : t[0])))

print(s)

