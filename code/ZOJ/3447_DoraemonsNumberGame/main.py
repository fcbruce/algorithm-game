#
#
# Author : fcbruce <fcbruce8964@gmail.com>
#
# Time : Tue 28 Jul 2015 04:32:51 PM CST
#
#

while True:
  try:
    n,k=map(int,raw_input().split())
  except EOFError,e:
    break

  a=map(int,raw_input().split());

  b=sorted(a)

  m=n;
  while m>1 :
    c=[]
    res=b[0]*b[1]+1
    c.append(res)
    for i in range(2,m): c.append(b[i])
    m-=1
    b=sorted(c);

  A=res


  m=n
  b=sorted(a)
  b.reverse()

  while m>1:
    c=[]
    res=1
    for i in range(0,min(k,m)): res*=b[i]
    res+=1
    c.append(res)
    for i in range(min(k,m),m): c.append(b[i])
    m-=min(k,m)
    m+=1
    b=(sorted(c))
    b.reverse()
  
  print abs(b[0]-A)



