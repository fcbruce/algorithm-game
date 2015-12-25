# -*- coding: utf-8 -*- 
#
# Author : fcbruce <fcbruce8964@gmail.com>
#
# Time : Sun 11 Oct 2015 09:36:51 AM CST
#
#

def gcd(a, b):
    if b == 0: return a
    return gcd(b, a % b)

n = input()

a = map(int, raw_input().split())

b = {}

g = []



for x in a:
    b[x] = b.get(x, 0) + 1

while b:
    x = max(b)
    print x,
    b[x] -= 1
    if b[x] == 0: del b[x]
    for y in g:
        d = gcd(x, y)
        b[d] -= 2
        if (b[d] == 0): del b[d]

    g.append(x)

