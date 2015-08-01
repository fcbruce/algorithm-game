#
#
# Author : fcbruce <fcbruce8964@gmail.com>
#
# Time : Fri 31 Jul 2015 10:19:07 AM CST
#
#

while True:
  try:
    n,m,t=map(int,raw_input().split())
  except EOFError ,ex:
    break

  res=0.0

  for i in range(t):
    c,b,a=map(int,raw_input().split())
    r=l=c/n
    if c%n!=0 : r+=1
    if l>b:res+=float(a*(c-n*b))/n
    elif r>b:res+=float(c%n)/n*a

  print '%.3f' % (res)
