n,k=map(int,raw_input().split())

a=raw_input()

c=dict();

for x in a:
	c[x]=c.get(x,0)+1

s=sorted(c.values())
s=reversed(s)

res=0;
	
for i in s:
	if k==0:
		break
	res+=min(k,i)**2
	k-=min(k,i)
	
print res
