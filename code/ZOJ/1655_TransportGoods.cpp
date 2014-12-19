/*
 *
 *	Author	:	fcbruce
 *
 *	Date	:	2014-08-17 13:42:52 
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
#define maxm 5005
#define maxn 101

using namespace std;

int fir[maxn];
int u[maxm],v[maxm],nex[maxm];
double w[maxm],d[maxn];
int e_max;
int g[maxn];

struct Heap_node
{
	double d;
	int v;
	bool operator < (const Heap_node &n)const
	{
		return d<n.d-eps;
	}
};

void add_edge(int _u,int _v,double _w)
{
	int e=e_max++;
	u[e]=_u;v[e]=_v;w[e]=_w;
	nex[e]=fir[u[e]];fir[u[e]]=e;
}

void dijkstra(int s)
{
	memset(d,0,sizeof d);
	d[s]=1;
	priority_queue<Heap_node> q;
	q.push( (Heap_node){d[s],s});
	
	while (!q.empty())
	{
		Heap_node x=q.top();q.pop();
		
		if (x.d<d[x.v]-eps)	continue;
		
		for (int e=fir[x.v];~e;e=nex[e])
		{
			if (d[v[e]]<d[u[e]]*w[e]-eps)
			{
				d[v[e]]=d[u[e]]*w[e];
				q.push( (Heap_node){d[v[e]],v[e]});
			}
		}
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/home/fcbruce/文档/code/t","r",stdin);
	#endif // ONLINE_JUDGE
	
	int n,m,_u,_v;
	double _w;
	
	while (~scanf( "%d%d",&n,&m))
	{
		e_max=0;
		memset(fir,-1,sizeof fir);
		
		for (int i=1;i<n;i++)
			scanf( "%d",&g[i]);
		
		for (int i=0;i<m;i++)
		{
			scanf( "%d%d%lf",&_u,&_v,&_w);
			add_edge(_v,_u,1-_w);
			add_edge(_u,_v,1-_w);
		}
		
		dijkstra(n);
		
		double res=0;
		
		for (int i=1;i<n;i++)
			res+=d[i]*g[i];
			
		printf( "%.2f\n",res);
	}
	
	return 0;
}



