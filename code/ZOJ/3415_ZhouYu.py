#
#
# Author : fcbruce <fcbruce8964@gmail.com>
#
# Time : Wed 22 Jul 2015 12:57:20 PM CST
#
#
import sys
for line in sys.stdin:
  n,m=map(float,line.split())
  if m==2 : print "%.8f" % (n*(n+1))
  else : print "%.8f" % (n*m/(m-2.0)-m/(m-2.0)**2*(1-(1/(m-1.0))**n))
