/*
 *
 *	Author	: 	fcbruce
 *
 *	Date	:	2014-08-11 13:24:46 
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
#define maxm 1000010
#define maxn 1001

using namespace std;

int G[maxn][maxn];
int QS[maxn];

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
	if (x==pre[x])	return x;
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
	
	int T_T,n;
	scanf( "%d",&T_T);
	
	while (T_T--)
	{
		scanf( "%d",&n);
		for (int i=0;i<n;i++)
			scanf( "%d",QS+i);
			
		e_max=0;
			
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<n;j++)
			{
				scanf( "%d",&G[i][j]);
			}
			
			for (int j=0;j<i;j++)
			{
				edge[e_max++]=(__edge){i,j,G[i][j]+QS[i]+QS[j]};
			}
		}
		
		sort(edge,edge+e_max);
		int total=n,res=0;
		for (itn i=0;i<n;i++)	pre[i]=i;
		
		for (int e=0;e<e_max;e++)
		{
			if (!__same(edge[e].u,edge[e].v))
			{
				total--;
				__merge(edge[e].u,edge[e].v);
				res+=edge[e].w;
			}
		}
		
		printf( "%d\n",res);
	}
	
	return 0;
}



