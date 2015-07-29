#
#
# Author : fcbruce <fcbruce8964@gmail.com>
#
# Time : Tue 28 Jul 2015 07:59:31 PM CST
#
#

while True:
  try:
    n=input()
  except Exception, e:
    break

  if n<10: 
    for i in xrange(9):
      print n,
    print
  else:
    n-=10
    for i in xrange(9):
      print n%(9-i)+i+1,
    print 
