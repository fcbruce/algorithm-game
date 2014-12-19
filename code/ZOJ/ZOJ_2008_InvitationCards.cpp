/*
 *
 *	Author	:	fcbruce
 *
 *	Date	:	2014-08-17 21:11:13 
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
#define maxm 1000001
#define maxn 1000001

using namespace std;

int fir[maxn];
int u[maxm],v[maxm],w[maxm],nex[maxm];
int e_max;
int d[maxn];

struct Heap_node
{
	int d,v;
	bool operator < (const Heap_node &n)const
	{
		return d>n.d;
	}
};

void add_edge(int _u,int _v,itn _w)
{
	int e=e_max++;
	u[e]=_u;v[e]=_v;w[e]=_w;
	nex[e]=fir[u[e]];fir[u[e]]=e;
}

void dijkstra(int s)
{
	memset(d,0x3f,sizeof d);
	d[s]=0;
	priority_queue<Heap_node>	q;
	q.push( (Heap_node){d[s],s});
	
	while (!q.empty())
	{
		Heap_node x=q.top();q.pop();
		
		if (x.d>d[x.v])	continue;
		
		for (int e=fir[x.v];~e;e=nex[e])
		{
			if (d[v[e]]>d[u[e]]+w[e])
			{
				d[v[e]]=d[u[e]]+w[e];
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
	
	int T_T;
	scanf( "%d",&T_T);
	
	while (T_T--)
	{
		int n,m;
		scanf( "%d%d",&n,&m);
		e_max=0;
		memset(fir,-1,sizeof fir);
		for (int i=0,_u,_v,_w;i<m;i++)
		{
			scanf( "%d%d%d",&_u,&_v,&_w);
			add_edge(_u,_v,_w);
		}
		
		int res=0;
		dijkstra(1);
		for (int i=1;i<=n;i++)	res+=d[i];
		
		e_max=0;
		memset(fir,-1,sizeof fir);
		for (int e=0;e<m;e++)
			add_edge(v[e],u[e],w[e]);
			
		dijkstra(1);
		for (int i=1;i<=n;i++)	res+=d[i];
		
		printf( "%d\n",res);		
		
	}
	
	return 0;
}



