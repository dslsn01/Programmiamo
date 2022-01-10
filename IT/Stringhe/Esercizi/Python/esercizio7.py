# file esercizio7.py
# -*- coding: utf-8 -*-

from __future__ import print_function

s = "3.14159"

t = s.split(".")

print("La parte intera di {} è {}, mentre la parte decimale è 0.{}.".format(s, t[0], t[1]))

