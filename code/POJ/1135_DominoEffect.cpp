/*
 *
 *	Author	:	fcbruce
 *
 *	Date	:	2014-08-11 19:30:17 
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
#define maxm sqr(505)
#define maxn 505

using namespace std;

int fir[maxn];
int u[maxm],v[maxm],w[maxm],nex[maxm];
int e_max;
int d[maxn];
int n,m;

struct Heap_node
{
	int d,u;
	bool operator < (const Heap_node &n)const
	{
		return d>n.d;
	}
};

void add_edge(int _u,int _v,int _w)
{
	int e=e_max++;
	u[e]=_u;v[e]=_v;w[e]=_w;
	nex[e]=fir[u[e]];fir[u[e]]=e;
}

void dijkstra(int s)
{
	memset(d,0x3f,sizeof d);
	d[s]=0;
	priority_queue<Heap_node> q;
	q.push( (Heap_node){0,s});
	while (!q.empty())
	{
		Heap_node x=q.top();q.pop();
		if (d[x.u]<x.d)	continue;
		
		for (int e=fir[x.u];~e;e=nex[e])
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
	
	int T_T=0;
	
	while (scanf( "%d %d",&n,&m),n||m)
	{
		e_max=0;
		memset(fir,-1,sizeof fir);
		
		for (int e=0,_u,_v,_w;e<m;e++)
		{
			scanf( "%d %d %d",&_u,&_v,&_w);
			add_edge(_u,_v,_w);
			add_edge(_v,_u,_w);
		}
		
		dijkstra(1);
		
		int MAX_key=-1;
		for (int i=1;i<=n;i++)
			if (MAX_key==-1 || d[i]>d[MAX_key])
				MAX_key=i;
		
		int MAX_normal=-1;
		for (int e=0;e<e_max;e+=2)
			if (MAX_normal==-1 || d[v[e]]+d[u[e]]+w[e]>d[v[MAX_normal]]+d[u[MAX_normal]]+w[MAX_normal])
				MAX_normal=e;
				
		printf( "System #%d\n",++T_T);
		
		if (u[MAX_normal]>v[MAX_normal])	swap(u[MAX_normal],v[MAX_normal]);
		
		if (MAX_normal==-1 || d[MAX_key]*2>=d[v[MAX_normal]]+d[u[MAX_normal]]+w[MAX_normal])
			printf( "The last domino falls after %.1f seconds, at key domino %d.\n",(double)d[MAX_key],MAX_key);
		else
			printf( "The last domino falls after %.1f seconds, between key dominoes %d and %d.\n",
			(double)(d[v[MAX_normal]]+d[u[MAX_normal]]+w[MAX_normal])/2,u[MAX_normal],v[MAX_normal]);
			
		putchar ( '\n');
	}
	
	return 0;
}



