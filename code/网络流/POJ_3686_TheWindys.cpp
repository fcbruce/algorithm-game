/*
 *
 *	Author	:	fcbruce
 *
 *	Date	:	2014-08-13 13:25:27 
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
#define maxm 4040404
#define maxn 4004

using namespace std;

int fir[maxn];
int u[maxm],v[maxm],cap[maxm],flow[maxm],cost[maxm],nex[maxm];
int e_max;
int Z[55][55];
int d[maxn],p[maxn];
bool inq[maxn];
int q[maxm<<2];

void add_edge(int _u,int _v,int _cap,int _cost)
{
	int e;
	e=e_max++;
	u[e]=_u;v[e]=_v;cap[e]=_cap;cost[e]=_cost;
	nex[e]=fir[u[e]];fir[u[e]]=e;
	e=e_max++;
	u[e]=_v;v[e]=_u;cap[e]=0;cost[e]=-_cost;
	nex[e]=fir[u[e]];fir[u[e]]=e;
	
}

void SPFA(int s)
{
	int f,r;
	memset(inq,0,sizeof inq);
	memset(d,0x3f,sizeof d);
	d[s]=0;
	q[f=r=0]=s;
	
	while (f<=r)
	{
		int x=q[f++];
		inq[x]=false;
		for (int e=fir[x];~e;e=nex[e])
		{
			if (cap[e]>flow[e] && d[v[e]]>d[u[e]]+cost[e])
			{
				d[v[e]]=d[u[e]]+cost[e];
				p[v[e]]=e;
				if (!inq[v[e]])
				{
					inq[v[e]]=true;
					q[++r]=v[e];
				}
			}
		}
	}
	
}

pair<int,int> min_cost_flow(int s,int t)
{
	int total_flow=0,total_cost=0;
	memset(flow,0,sizeof flow);
	
	for (;;)
	{
		SPFA(s);
		
		if (d[t]==INF)	break;
		
		int _f=INF;
		for (int e=p[t];;e=p[u[e]])
		{
			_f=min(_f,cap[e]-flow[e]);
			if (u[e]==s)	break;
		}
		
		for (int e=p[t];;e=p[u[e]])
		{
			flow[e]+=_f;
			flow[e^1]-=_f;
			if (u[e]==s)	break;
		}
		
		total_flow+=_f;
		total_cost+=_f*d[t];
	}
	
	return make_pair(total_cost,total_flow);
}


int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/home/fcbruce/文档/code/t","r",stdin);
	#endif // ONLINE_JUDGE
	
	int T_T,n,m;
	scanf( "%d",&T_T);
	
	while (T_T--)
	{
		e_max=0;
		memset(fir,-1,sizeof fir);
		scanf( "%d%d",&n,&m);
		int s=n*m+n+1,t=s+1;
		for (int i=0;i<n;i++)
		{
			add_edge(s,i,1,0);
			for (int j=0;j<m;j++)
			{
				scanf( "%d",&Z[i][j]);
			}
		}
		
		for (int i=0;i<m;i++)
		{
			for (int j=0;j<n;j++)
			{
				add_edge(n+i*n+j,t,1,0);
				for (int k=0;k<n;k++)
				{
					add_edge(k,n+i*n+j,1,Z[k][i]*(j+1));
				}
			}
		}
		
		pair<int,int> res=min_cost_flow(s,t);
		
		printf( "%.6f\n",(double)res.first/n);
	}
	
	return 0;
}



