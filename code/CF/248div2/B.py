#
#
# Author : fcbruce <fcbruce8964@gmail.com>
#
# Time : Sun 02 Nov 2014 09:16:30 AM CST
#
#

n=input()
a=map(int,raw_input().split())
m=input()
s=[0 for i in xrange(n+1)];
for i in xrange(n):
  s[i+1]=s[i]+a[i]

b=sorted(a)

s2=[0 for i in xrange(n+1)]
for i in xrange(n):
  s2[i+1]=s2[i]+b[i]

for i in xrange(m):
  t,l,r=map(int,raw_input().split())
  if t==1 :
    print s[r]-s[l-1]
  else:
    print s2[r]-s2[l-1]
