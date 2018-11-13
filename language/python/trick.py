#encoding:utf-8
from __future__ import print_function

d = {'a':1, 'b':2, 'c':3}

for key in d.keys():
    print(key)

for value in d.values():
    print(value)

for key, value in d.items():
    print(key, value)

def foo(n):
    n = int(n)
    assert n != 0, 'n is zero'
    return 10 / n

foo(0)