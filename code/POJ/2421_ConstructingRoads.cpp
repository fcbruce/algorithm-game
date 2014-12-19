/*
 *
 *	Author	: 	fcbruce
 *
 *	Date	:	2014-08-11 13:05:12 
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
#define maxm 10010
#define maxn 101

using namespace std;

int G[maxn][maxn];

struct __edge
{
	int u,v,w;
	bool operator < (const __edge &e)const
	{
		return w<e.w;
	}
}edge[maxm];
int e_max;
int pre[maxn];

int root(int x)
{
	if (pre[x]==x)	return x;
	return pre[x]=root(pre[x]);
}

bool __same(int x,int y)
{
	return root(x)==root(y);
}

void __merge(int x,int y)
{
	pre[root(x)]=root(y);
}


int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/home/fcbruce/文档/code/t","r",stdin);
	#endif // ONLINE_JUDGE
	
	int n;
	scanf( "%d",&n);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
			scanf( "%d",&G[i][j]);
		
		for (int j=1;j<i;j++)
			edge[e_max++]=(__edge){i,j,G[i][j]};
	}
	
	for (int i=0;i<=n;i++)	pre[i]=i;
	
	int m;
	scanf( "%d",&m);
	int total=n;
	for (int i=0,_u,_v;i<m;i++)
	{
		scanf( "%d%d",&_u,&_v);
		if (!__same(_u,_v))
		{
			__merge(_u,_v);
			total--;
		}
	}
	
	sort(edge,edge+e_max);
	int res=0;
	
	for (int e=0;e<e_max && total>1;e++)
	{
		if (!__same(edge[e].u,edge[e].v))
		{
			__merge(edge[e].u,edge[e].v);
			res+=edge[e].w;
			total--;
		}
	}
	
	printf( "%d\n",res);
	
	return 0;
}



