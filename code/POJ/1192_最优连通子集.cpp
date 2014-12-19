/*
 *
 *	Author	:	fcbruce
 *
 *	Date	:	2014-08-18 15:49:44 
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
#define maxm 233333
#define maxn 1010

using namespace std;

struct Point
{
	int x,y,w;
	int manhatton_dis(Point p)
	{
		return abs(x-p.x)+abs(y-p.y);
	}
}p[maxn];

int fir[maxn];
int u[maxm],v[maxm],nex[maxm];
int e_max;
bool vis[maxn];
int dp[maxn][2];


void add_edge(int _u,int _v)
{
	int e=e_max++;
	u[e]=_u;v[e]=_v;
	nex[e]=fir[u[e]];fir[u[e]]=e;
}

void dfs(int s)
{
	vis[s]=true;
	dp[s][0]=0;
	dp[s][1]=p[s].w;
	
	for (int e=fir[s];~e;e=nex[e])
	{
		if (!vis[v[e]])
		{
			dfs(v[e]);
			dp[s][0]=max(dp[s][0],max(dp[v[e]][0],dp[v[e]][1]));
			if (dp[v[e]][1]>0)
				dp[s][1]+=dp[v[e]][1];
		}
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/home/fcbruce/文档/code/t","r",stdin);
	#endif // ONLINE_JUDGE
	
	int n;
	scanf( "%d",&n);
	e_max=0;
	memset(fir,-1,sizeof fir);
	unsigned LL seed=233333ull^(~0ull);
	
	for (int i=0;i<n;i++)
	{
		scanf( "%d%d%d",&p[i].x,&p[i].y,&p[i].w);
		seed*=233;
		for (int j=0;j<i;j++)
		{
			if (p[i].manhatton_dis(p[j])==1)
			{
				add_edge(i,j);
				add_edge(j,i);
			}
		}	
	}
	
	memset(vis,0,sizeof vis);
	int root=seed%n;
	dfs(root);
	
	printf( "%d\n",max(dp[root][0],dp[root][1]));
	
	
	return 0;
}



