/*
 *
 *	Author	:	fcbruce
 *
 *	Date	:	2014-08-11 20:28:55 
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
#define maxn 1001

using namespace std;

int fir[maxn];
int u[maxm],v[maxm],w[maxm],nex[maxm];
int e_max;
int d[maxn];

int _time[maxn];
char first[maxn][5],last[maxn][5];
char buff[100];

void add_edge(int _u,int _v,int _w)
{
	int e=e_max++;
	u[e]=_u;v[e]=_v;w[e]=_w;
	nex[e]=fir[u[e]];fir[u[e]]=e;
}

struct Heap_node
{
	int d,u;
	bool operator < (const Heap_node n)const
	{
		return d>n.d;
	}
};

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
	
	int n;
	
	while (scanf( "%d",&n),n)
	{
		e_max=0;
		memset(fir,-1,sizeof fir);
		
		for (int i=0;i<n;i++)
		{
			scanf( "%d %s",&_time[i],buff);
			strcpy(last[i],buff+strlen(buff)-4);
			buff[4]='\0';
			strcpy(first[i],buff);
		}
		
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<n;j++)
			{
				if (strcmp(last[i],first[j])==0)
					add_edge(i,j,_time[i]);
			}
		}
		
		dijkstra(0);
		
		printf( "%d\n",d[n-1]==INF?-1:d[n-1]);
	}
	
	return 0;
}



