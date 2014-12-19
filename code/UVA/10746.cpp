/*
 *
 *	Author	:	fcbruce
 *
 *	Date	:	2014-09-05 20:37:26 
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

#define maxm 2333
#define maxn 64

using namespace std;

int fir[maxn];
int u[maxm],v[maxm],cap[maxm],flow[maxm],nex[maxm];
double cost[maxm];
int e_max;
double d[maxn];
int p[maxn];
bool inq[maxn];
int q[maxm<<3];

inline void add_edge(int _u,int _v,int _cap,double _cost)
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
	memset(inq,0,sizeof inq);
	memset(d,0x7f,sizeof d);
	int f,r;
	d[s]=0;
	q[f=r=0]=s;
	while (f<=r)
	{
		int x=q[f++];
		inq[x]=false;
		for (int e=fir[x];~e;e=nex[e])
		{
			if (cap[e]>flow[e] && d[v[e]]>d[u[e]]+cost[e]+eps)
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

pair<double,int> min_cost_flow(int s,int t)
{
	memset(flow,0,sizeof flow);
	double total_cost=0;
	int total_flow=0;
	
	for (;;)
	{
		SPFA(s);
		
		if (d[t]>INF)	break;
		
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
		
		total_cost+=d[t]*_f;
		total_flow+=_f;
	}
	
	return make_pair(total_cost,total_flow);
}

int main()
{
#ifdef FCBRUCE
	freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE
	
	int n,m;
	
	while (scanf( "%d%d",&n,&m),n||m)
	{
		int s=0,t=n+m+1;
		
		e_max=0;
		memset(fir,-1,sizeof fir);
		
		double w;
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=m;j++)
			{
				scanf( "%lf",&w);
				add_edge(i,n+j,1,w);
			}
		}
		
		for (int i=1;i<=n;i++)
			add_edge(s,i,1,0);
		
		for (int j=1;j<=m;j++)
			add_edge(j+n,t,1,0);
		
		auto res=min_cost_flow(s,t);
		
		printf( "%.2f\n",res.first/res.second+eps);
	}
	
	return 0;
}



