/*
 *
 *	Author	:	fcbruce
 *
 *	Date	:	2014-08-27 21:32:41 
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

#define maxm 5050505
#define maxn 1001

using namespace std;

struct __city
{
	int x,y;
}city[maxn];

int n,m;
int sub[10][maxn],cap[10],cost[10];
int pre[maxn];
int MIN;

struct __edge
{
	int u,v,w;
	bool operator < (const __edge &e)const
	{
		return w<e.w;
	}
}edge[maxm];
itn e_max;

int root(int x)
{
	if (x==pre[x])	return x;
	return pre[x]=root(pre[x]);
}

bool same(int x,int y)
{
	return root(x)==root(y);
}

void __merge(int x,int y)
{
	pre[root(x)]=root(y);
}

int kruskal(int bit)
{
	int cnt=n;
	for (int i=1;i<=n;i++)	pre[i]=i;
	for (int i=0;i<m;i++)
	{
		if (bit&1<<i)
		{
			for (int j=1;j<cap[i];j++)
			{
				if (!same(sub[i][j],sub[i][j-1]))
				{
					cnt--;
					__merge(sub[i][j],sub[i][j-1]);
				}
			}
		}
	}
	
	int res=0;
	
	for (int i=0;i<e_max;i++)
	{
		if (!same(edge[i].u,edge[i].v))
		{
			res+=edge[i].w;
			cnt--;
			__merge(edge[i].u,edge[i].v);
		}

		if (cnt==1) break;
	}
	
	return res;
}

void dfs(int x,int __res,int bit)
{
	if (x==m)
	{
		MIN=min(MIN,__res+kruskal(bit));
		return ;
	}
	
	dfs(x+1,__res,bit);

	dfs(x+1,__res+cost[x],bit|1<<x);
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/home/fcbruce/文档/code/t","r",stdin);
	#endif // ONLINE_JUDGE
	
	int T_T;
	scanf( "%d",&T_T);
	
	while (T_T--)
	{		
		scanf( "%d%d",&n,&m);
		for (int i=0;i<m;i++)
		{
			scanf( "%d%d",&cap[i],&cost[i]);
			for (int j=0;j<cap[i];j++)
				scanf( "%d",&sub[i][j]);
		}
		
		
		e_max=0;
		for (int i=1;i<=n;i++)
		{
			scanf( "%d%d",&city[i].x,&city[i].y);
			for (int j=1;j<i;j++)
				edge[e_max++]=(__edge){i,j,sqr(city[i].x-city[j].x)+sqr(city[i].y-city[j].y)};
		}
		
		sort(edge,edge+e_max);
		
		MIN=INF;
		dfs(0,0,0);
		
		printf( "%d\n",MIN);
		if (T_T)	putchar( '\n');
	}
	
	return 0;
}



