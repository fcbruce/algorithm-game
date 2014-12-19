/*
 *
 *	Author	:	fcbruce
 *
 *	Date	:	2014-08-17 14:25:47 
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

int fir[maxn];
int u[maxm],v[maxm],w[maxm],nex[maxm];
int e_max;
int dp[maxn][12],rest[maxn][12];
int q[maxm<<4];
bool inq[maxn];
int shoe[maxn][maxn];
int A,B,M,L,K;


void add_edge(int _u,int _v,int _w)
{
	int e=e_max++;
	u[e]=_u;v[e]=_v;w[e]=_w;
	nex[e]=fir[u[e]];fir[u[e]]=e;
}

void init()
{
	int f,r;
	memset(shoe,0x3f,sizeof shoe);
	
	for (int i=1;i<=A+B;i++)
	{
		memset(inq,0,sizeof inq);
		shoe[i][i]=0;
		q[f=r=0]=i;
		while (f<=r)
		{
			int x=q[f++];
			inq[x]=false;
			for (int e=fir[x];~e;e=nex[e])
			{
				if (shoe[i][v[e]]>shoe[i][u[e]]+w[e])
				{
					shoe[i][v[e]]=shoe[i][u[e]]+w[e];
					if (v[e]<=A && !inq[v[e]])
					{
						q[++r]=v[e];
						inq[v[e]]=true;
					}
				}
			}
		}
	}
}

void solve(int s)
{
	int f,r;
	memset(inq,0,sizeof inq);
	memset(dp,0x3f,sizeof dp);
	dp[s][0]=0;
	q[f=r=0]=s;
	while (f<=r)
	{
		int x=q[f++];
		inq[x]=false;
		
		for (int i=0;i<=K;i++)
		{
			for (int e=fir[x];~e;e=nex[e])
			{
				if (dp[v[e]][i]>dp[u[e]][i]+w[e])
				{
					dp[v[e]][i]=dp[u[e]][i]+w[e];
					if (!inq[v[e]])
					{
						q[++r]=v[e];
						inq[v[e]]=true;
					}
				}
			}
			
			if (i==K)	continue;
			for (int _v=1;_v<=A+B;_v++)
			{
				if (shoe[x][_v]<=L && dp[_v][i+1]>dp[x][i])
				{
					dp[_v][i+1]=dp[x][i];
					if (!inq[_v])
					{
						q[++r]=_v;
						inq[_v]=true;
					}
				}
			}
		}
	}
	
}

int main()
{
#ifdef FCBRUCE
    freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE
	
	int T_T;
	scanf( "%d",&T_T);
	
	while (T_T--)
	{
		scanf( "%d%d%d%d%d",&A,&B,&M,&L,&K);
		e_max=0;
		memset(fir,-1,sizeof fir);
		
		for (int i=0,_u,_v,_w;i<M;i++)
		{
			scanf( "%d%d%d",&_u,&_v,&_w);
			add_edge(_u,_v,_w);
			add_edge(_v,_u,_w);
		}
		
		init();
		
		solve(A+B);
		
		int MIN=INF;
		for (int i=0;i<=K;i++)
			MIN=min(MIN,dp[1][i]);
			
		printf( "%d\n",MIN);
	}
	
	return 0;
}



