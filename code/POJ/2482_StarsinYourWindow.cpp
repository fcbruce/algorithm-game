/*
 *
 *	Author	:	fcbruce
 *
 *	Date	:	2014-08-21 09:19:53 
 *
 */
#include <cstdio>
#include <iostream>
#include <sstream>
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

#ifdef _WIN32
	#define lld "%I64d"
#else
	#define lld "%lld"
#endif

#define maxm 20007
#define maxn 20007

using namespace std;

struct __edge
{
	long long a,b,y,brightness;
	bool operator < (const __edge &e)const
	{
		if (y==e.y)	return brightness<e.brightness;
		return y<e.y;
	}
}edge[maxm];

long long maxv[maxn<<2],addv[maxn<<2];
long long X[maxn];

inline void pushup(int k)
{
	maxv[k]=max(maxv[k*2+1],maxv[k*2+2]);
}

inline void pushdown(int k)
{
	if (addv[k])
	{
		int lc=k*2+1,rc=k*2+2;
		addv[lc]+=addv[k];addv[rc]+=addv[k];
		maxv[lc]+=addv[k];maxv[rc]+=addv[k];
		addv[k]=0;
	}
}

void update(int a,int b,long long v,int k,int l,int r)
{
	if (b<=l || r<=a)	return ;
	if (a<=l && r<=b)
	{
		addv[k]+=v;
		maxv[k]+=v;
		return ;
	}
	
	pushdown(k);
	update(a,b,v,k*2+1,l,l+r>>1);
	update(a,b,v,k*2+2,l+r>>1,r);
	pushup(k);
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/home/fcbruce/文档/code/t","r",stdin);
	#endif // ONLINE_JUDGE
	
	long long n,w,h;
	
	while (~scanf( lld lld lld,&n,&w,&h))
	{
		memset(maxv,0,sizeof maxv);
		memset(addv,0,sizeof addv);
		LL x,y,brightness;
		for (int i=0;i<n;i++)
		{
			scanf( lld lld lld,&x,&y,&brightness);
			edge[i]=(__edge){x,x+w,y,brightness};
			edge[i+n]=(__edge){x,x+w,y+h,-brightness};
			X[i]=x;
			X[i+n]=x+w;
		}
		
		n<<=1;
		sort(edge,edge+n);
		sort(X,X+n);
		int m=unique(X,X+n)-X;
		
		long long MAX=0;
		for (int i=0;i<n;i++)
		{
			int a=lower_bound(X,X+m,edge[i].a)-X;
			int b=lower_bound(X,X+m,edge[i].b)-X;
			
			update(a,b,edge[i].brightness,0,0,m);
			MAX=max(MAX,maxv[0]);
		}
		
		printf( lld "\n",MAX);
	}
	
	return 0;
}



