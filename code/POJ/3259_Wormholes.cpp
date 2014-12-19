/*
 *
 *	Author	:	fcbruce
 *
 *	Date	:	2014-08-19 09:58:04 
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
#define maxm 8964
#define maxn 505

using namespace std;

int n,m,wh;
int fir[maxn];
int u[maxm],v[maxm],w[maxm],nex[maxm];
int e_max;
int d[maxn];
int st[maxm<<3];
int cnt[maxn];

bool inst[maxn];

void add_edge(int _u,int _v,int _w)
{
	int e=e_max++;
	u[e]=_u;v[e]=_v;w[e]=_w;
	nex[e]=fir[u[e]];fir[u[e]]=e;
}

bool negative_loop()
{
	int top=-1;
	for (int i=1;i<=n;i++)
	{
		st[++top]=i;
		cnt[i]=1;
	}
	memset(d,0,sizeof d);
	memset(inst,1,sizeof inst);
	
	while (top>-1)
	{
		int x=st[top--];
		inst[x]=false;
		for (int e=fir[x];~e;e=nex[e])
		{
			if (d[v[e]]>d[u[e]]+w[e])
			{
				d[v[e]]=d[u[e]]+w[e];
				if (!inst[v[e]])
				{
					inst[v[e]]=true;
					st[++top]=v[e];
					if (++cnt[v[e]]>n)	return true;
				}
			}
		}
	}
	
	return false;
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
		scanf( "%d%d%d",&n,&m,&wh);
		e_max=0;
		memset(fir,-1,sizeof fir);
		
		for (int i=0,u,v,w;i<m;i++)
		{
			scanf( "%d%d%d",&u,&v,&w);
			add_edge(u,v,w);
			add_edge(v,u,w);
		}
		
		for (int i=0,u,v,w;i<wh;i++)
		{
			scanf( "%d%d%d",&u,&v,&w);
			add_edge(u,v,-w);
		}
		
		if (negative_loop())
			puts( "YES");
		else
			puts( "NO");

	}
	
	return 0;
}



