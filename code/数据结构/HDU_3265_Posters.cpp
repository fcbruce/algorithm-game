/*
 *
 *	Author	:	fcbruce
 *
 *	Date	:	2014-08-14 09:15:00 
 *
 */
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <cctype>
#include <cmath>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <set>
#define sqr(x) ((x)*(x))
#define LL long long
#define itn int
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
#define eps 1e-10
#define maxm 
#define maxn 50007

using namespace std;

struct __edge
{
	int l,r,h,v;
	bool operator < (const __edge &e)const
	{
		return h<e.h;
	}
}edge[maxn<<4];

int val[maxn<<2],sum[maxn<<2];

inline void pushup(int k,int l,int r)
{
	if (val[k])
		sum[k]=r-l;
	else	if (r-l==1)
		sum[k]=0;
	else
		sum[k]=sum[k*2+1]+sum[k*2+2];
}

void update(int a,int b,int v,int k,int l,int r)
{
	if (b<=l || r<=a)	return ;
	if (a<=l && r<=b)
	{
		val[k]+=v;
		pushup(k,l,r);
	}
	else
	{
		update(a,b,v,k*2+1,l,l+r>>1);
		update(a,b,v,k*2+2,l+r>>1,r);
		pushup(k,l,r);
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/home/fcbruce/文档/code/t","r",stdin);
	#endif // ONLINE_JUDGE
	
	int n,m;
	
	while (scanf( "%d",&m),m)
	{
		int e_max=0;
		memset(val,0,sizeof val);
		memset(sum,0,sizeof sum);
		n=0;
		
		for (int i=0,x1,y1,x2,y2,x3,y3,x4,y4;i<m;i++)
		{
			scanf( "%d %d %d %d",&x1,&y1,&x2,&y2);
			scanf( "%d %d %d %d",&x3,&y3,&x4,&y4);
			edge[e_max++]=(__edge){x1,x2,y1,1};
			edge[e_max++]=(__edge){x1,x2,y3,-1};
			edge[e_max++]=(__edge){x1,x2,y4,1};
			edge[e_max++]=(__edge){x1,x2,y2,-1};
			edge[e_max++]=(__edge){x1,x3,y3,1};
			edge[e_max++]=(__edge){x1,x3,y4,-1};
			edge[e_max++]=(__edge){x4,x2,y3,1};
			edge[e_max++]=(__edge){x4,x2,y4,-1};
			
			n=max(n,x2);
			
			
		}
		
		sort(edge,edge+e_max);
		
		int last=0;
		long long area=0;
		
		for (int i=0;i<e_max;i++)
		{
			area+=(long long)sum[0]*(edge[i].h-last);
			update(edge[i].l,edge[i].r,edge[i].v,0,0,n);
			last=edge[i].h;
		}
		
		printf( "%I64d\n",area);
	}
	
	return 0;
}



