/*
 *
 *	Author	:	fcbruce
 *
 *	Date	:	2014-08-26 09:19:49 
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

#define maxm 233333
#define maxn 1001

using namespace std;

int n,ml,md;
int _time[maxn];
int fir[maxn];
int u[maxm],v[maxm],w[maxm],nex[maxm];
int e_max=0;
int d[maxn];
int inc[maxn];
int q[maxm<<3];
bool inq[maxn];

void add_edge(int _u,int _v,LL _w)
{
	int e=e_max++;
	u[e]=_u;v[e]=_v;w[e]=_w;
	nex[e]=fir[u[e]];fir[u[e]]=e;
}

bool SPFA(int s)
{
	memset(d,0x3f,sizeof d);
	memset(inq,0,sizeof inq);
	memset(inc,0,sizeof inc);
	int f,r;
	d[s]=0;
	q[f=r=0]=s;
	while (f<=r)
	{
		int x=q[f++];
		inq[x]=false;
		for (int e=fir[x];~e;e=nex[e])
		{
			if (d[v[e]]>d[u[e]]+w[e])
			{
				d[v[e]]=d[u[e]]+w[e];
				if (!inq[v[e]])
				{
					inq[v[e]]=true;
					q[++r]=v[e];
					if (++inc[v[e]]>n)	return false;
				}
			}
		}
	}
	
	return true;
}


int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/home/fcbruce/文档/code/t","r",stdin);
	#endif // ONLINE_JUDGE
	
	scanf( "%d%d%d",&n,&ml,&md);
	e_max=0;
	memset(fir,-1,sizeof fir);
	
	for (int i=1;i<=n;i++)
		add_edge(i,i-1,0);
		
	for (int i=0,u,v,w;i<ml;i++)
	{
		scanf( "%d%d%d",&u,&v,&w);
		add_edge(u,v,w);
	}
	
	for (int i=0,u,v,w;i<md;i++)
	{
		scanf( "%d%d%d",&u,&v,&w);
		add_edge(v,u,-w);
	}
	
	if (SPFA(1))
	{
		if (d[n]==INF)
			puts( "-2");
		else
			printf( "%d\n",d[n]);
	}
	else
		puts( "-1");

	return 0;
}



