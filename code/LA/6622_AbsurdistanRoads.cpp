/*
 *
 *	Author	:	fcbruce
 *
 *	Date	:	2014-08-27 08:51:06 
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

#define maxm 2333333
#define maxn 2333
#define log_maxn 12

using namespace std;

int G[maxn][maxn];
int parent[log_maxn][maxn];
int depth[maxn],mincost[maxn];
int dep[maxn];
bool vis[maxn];
int n;


void prim(int s)
{
	memset(mincost,0x3f,sizeof mincost);
	memset(vis,0,sizeof vis);
	mincost[s]=0;
	
	for (;;)
	{
		int v=-1;
		for (int i=1;i<=n;i++)
			if (!vis[i] && (v==-1 || mincost[v]>mincost[i]))
				v=i;
				
		if (v==-1)	break;
		
		if ( ~parent[0][v])
			printf( "%d %d %d\n",v,parent[0][v],G[parent[0][v]][v]);
			
		depth[v]=depth[parent[0][v]]+1;
		dep[v]=dep[parent[0][v]]+G[parent[0][v]][v];
		vis[v]=true;
		
		for (int i=1;i<=n;i++)
		{
			if (!vis[i] && mincost[i]>G[v][i])
			{
				mincost[i]=G[v][i];
				parent[0][i]=v;
			}
		}
	}
}

void init_lca()
{
	for (int k=0;k+1<log_maxn;k++)
	{
		for (int i=0;i<=n;i++)
		{
			if (parent[k][i]<0)
				parent[k+1][i]=-1;
			else
				parent[k+1][i]=parent[k][parent[k][i]];
		}
	}
}

int lca(int u,int v)
{
	if (depth[u]>depth[v])	swap(u,v);
	
	for (itn k=0;k<log_maxn;k++)
		if (depth[v]-depth[u]>>k&1)
			v=parent[k][v];
			
	if (u==v)
		return v;
		
	for (int k=log_maxn-1;k>=0;k--)
	{
		if (parent[k][u]!=parent[k][v])
		{
			u=parent[k][u];
			v=parent[k][v];
		}
	}
	
	return parent[0][u];
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/home/fcbruce/文档/code/t","r",stdin);
	#endif // ONLINE_JUDGE
	
	bool first=true;
	
	while (~scanf( "%d",&n))
	{
		if (!first)	putchar( '\n');
			first=false;
		
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				scanf( "%d",&G[i][j]);

		memset(parent,-1,sizeof parent);
		memset(depth,0,sizeof depth);
		memset(dep,0,sizeof dep);
		
		int root=1;
		prim(root);
		
		init_lca();
		
		int u=-1,v=-1,MIN=INF;
		for (int i=1;i<=n;i++)
		{
			for (int j=i+1;j<=n;j++)
			{
				int dis=dep[i]+dep[j]-2*dep[lca(i,j)];
				
				if (dis!=G[i][j] && MIN>G[i][j])
				{
					u=i;
					v=j;
//					if (depth[u]>depth[v])	swap(u,v);//make sure that u is father of v
					MIN=G[i][j];
				}
			}
		}
		
		if (MIN==INF)
		{
			u=1;v=2;
		}
		printf( "%d %d %d\n",u,v,G[u][v]);
	}
	
	return 0;
}



