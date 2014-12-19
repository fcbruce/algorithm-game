/*
 *
 *	Author	:	fcbruce
 *
 *	Date	:	2014-08-27 21:02:19 
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

#define maxm 150000
#define maxn 30303

using namespace std;

itn fir[maxn];
int u[maxm],v[maxm],w[maxm],nex[maxm];
int e_max;
int d[maxn];
int q[maxm];
bool inq[maxn];

void add_edge(int _u,int _v,int _w)
{
	int e=e_max++;
	u[e]=_u;v[e]=_v;w[e]=_w;
	nex[e]=fir[u[e]];fir[u[e]]=e;
}

void SPFA(int s)
{
	int f,r;
	memset(d,0x3f,sizeof d);
	memset(inq,0,sizeof inq);
	d[s]=0;
	q[f=r=0]=s;
	while (f<=r)
	{
		int x=q[r--];
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
				}
			}
		}
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/home/fcbruce/文档/code/t","r",stdin);
	#endif // ONLINE_JUDGE
	
	int n,m;
	
	scanf( "%d%d",&n,&m);
	
	e_max=0;
	memset(fir,-1,sizeof fir);
	
	for (int i=0,u,v,w;i<m;i++)
	{
		scanf( "%d%d%d",&u,&v,&w);
		add_edge(u,v,w);
	}
	
	SPFA(1);
	
	printf( "%d\n",d[n]);
	
	return 0;
}



